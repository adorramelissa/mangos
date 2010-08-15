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

class ListenerGameEvent : public Listener
{
public:
    virtual void EventGameEventStarted(const EventInfoGameEvent &) {}
    virtual void EventGameEventStopped(const EventInfoGameEvent &) {}
};

class EventGameEventMgr : public EventSystemMgr<ListenerGameEvent> {};

#define sEventGameEventMgr MaNGOS::Singleton<EventGameEventMgr>::Instance()

// Debug purposes:
class EventDebugGameEvent : public ListenerGameEvent
{
public:
    EventDebugGameEvent()
    {
        sEventGameEventMgr.Listener += this;
    }
    void EventGameEventStarted(const EventInfoGameEvent &) { sLog.outDebug("============EventGameEventStarted============"); }
    void EventGameEventStopped(const EventInfoGameEvent &) { sLog.outDebug("============EventGameEventStopped============"); }
};
extern EventDebugGameEvent eventDebugGameEvent;

#endif // __EVENTGAMEEVENTMGR_H__
