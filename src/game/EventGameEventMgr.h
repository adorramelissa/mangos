/*
 *  EventGameEventMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTGAMEEVENTMGR_H__
#define __EVENTGAMEEVENTMGR_H__

#include "EventSystemMgr.h"

struct GameEventData;

struct EventInfoGameEvent : public EventInfo
{
    uint16 id;
    const GameEventData &gameEvent;

    EventInfoGameEvent(uint16 id_, const GameEventData &gameEvent_)
    : EventInfo(), id(id_), gameEvent(gameEvent_) {}
};

class EventListenerGameEvent : public EventListener
{
public:
    virtual void EventGameEventStarted(const EventInfoGameEvent &) {}
    virtual void EventGameEventStopped(const EventInfoGameEvent &) {}
};

// Debug purposes:
#ifdef EVENTDEBUGOUT
class EventDebugGameEvent : public EventListenerGameEvent
{
public:
    EventDebugGameEvent()
    {
        sEventSystemMgr(EventListenerGameEvent).RegisterListener(this);
    }
    void EventGameEventStarted(const EventInfoGameEvent &info);
    void EventGameEventStopped(const EventInfoGameEvent &info);
};
extern EventDebugGameEvent eventDebugGameEvent;
#endif

#endif // __EVENTGAMEEVENTMGR_H__
