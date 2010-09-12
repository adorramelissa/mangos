/*
 *  EventSystemMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTSYSTEMMGR_H__
#define __EVENTSYSTEMMGR_H__

#include <time.h>

#include "Policies/Singleton.h"
#include "Utilities/UnorderedMapSet.h"
#include "Timer.h"
#include "Log.h"

// Used by all custom eventlistener for debug purposes and to change log level fast
#define EVENTDEBUGOUT
#ifdef EVENTDEBUGOUT
#define EVENTLOG(...) sLog.outString(__VA_ARGS__)
#endif

// Struct to hold all important informations about event, will be overloaded by specific events
// to deliver information about that event
struct EventInfo
{
    time_t timestamp;

    EventInfo() : timestamp(time(NULL)) {}
};

// Basic listener, will be overloaded by specific listener
class EventListener
{
protected:
    EventListener() {}
};

// Main dispatcher for all events. Also the point where listener have to register
template<typename ListenerType>
class EventSystemMgr
{
public:
    // Register a listener of a specific type
    inline void RegisterListener(ListenerType *listener)
    {
        _list.insert(listener);
    }

    // Triggers an event and informs all registered listeners that match the eventtype
    template<typename EventType>
    void TriggerEvent(const EventType &event, void (ListenerType::*func)(const EventType &))
    {
        for (typename UNORDERED_SET<ListenerType *>::const_iterator it = _list.begin(); it != _list.end(); ++it)
        {
            ((*it)->*func)(event);
        }
    }

private:
    UNORDERED_SET<ListenerType *> _list;
};

#define sEventSystemMgr(Type) MaNGOS::Singleton<EventSystemMgr<Type> >::Instance()

#endif // __EVENTSYSTEMMGR_H__
