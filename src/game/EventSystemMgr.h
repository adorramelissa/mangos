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

#include "Policies/Singleton.h"
#include "Utilities/UnorderedMapSet.h"
#include "Timer.h"
#include "Log.h"

struct EventInfo
{
    uint32 time;

    EventInfo() : time(getMSTime()) {}
};

template <typename U>
struct EventInfoSubject : public EventInfo
{
    const U &subject;

    EventInfoSubject(const U &subject_)
    : EventInfo(), subject(subject_) {}
};

class EventListener {};

template<typename ListenerType>
class EventSystemMgr
{
public:
    inline void RegisterListener(ListenerType *listener)
    {
        _list.insert(listener);
    }

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
