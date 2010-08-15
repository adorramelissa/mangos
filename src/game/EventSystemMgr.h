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
#include "Utilities/UnorderedMap.h"
#include "Utilities/UnorderedSet.h"
#include "Timer.h"
#include "Player.h"

class PrintEvents;

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

class Listener {};

template<typename ListenerType>
struct ListenerSet {
    typedef UNORDERED_SET<ListenerType *> Type;
};

template<typename ListenerType>
struct EventConnect
{
public:
    inline EventConnect& operator+=(ListenerType *listener)
    {
        RegisterListener(listener);
        return *this;
    }

    inline void RegisterListener(ListenerType *listener)
    {
        list.insert(listener);
    }

    template<typename EventType>
    void InformListener(const EventType &event, void (ListenerType::*func)(const EventType&))
    {
        for (typename ListenerSet<ListenerType>::Type::const_iterator it = list.begin(); it != list.end(); ++it)
        {
            ((*it)->*func)(event);
        }
    }
private:
    typename ListenerSet<ListenerType>::Type list;
};

template<typename ListenerType>
class EventSystemMgr
{
public:
    template<typename EventType>
    inline void TriggerEvent(const EventType &event, void (ListenerType::*func)(const EventType&))
    {
        Listener.InformListener(event, func);
    }

    EventConnect<ListenerType> Listener;
};

// #define sEventSystemMgr MaNGOS::Singleton<EventSystemMgr>::Instance()

#endif // __EVENTSYSTEMMGR_H__
