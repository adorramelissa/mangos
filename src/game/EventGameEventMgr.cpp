/*
 *  EventGameEventMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventGameEventMgr.h"
#include "Policies/SingletonImp.h"
#include "GameEventMgr.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerGameEvent>);
EventDebugGameEvent eventDebugGameEvent;

void EventDebugGameEvent::EventGameEventStarted(const EventInfoGameEvent &info)
{
    EVENTLOG("EventGameEventStarted - id:%u desc:%s", info.id, info.gameEvent.description.c_str());
}

void EventDebugGameEvent::EventGameEventStopped(const EventInfoGameEvent &info)
{
    EVENTLOG("EventGameEventStopped - id:%u desc:%s", info.id, info.gameEvent.description.c_str());
}
