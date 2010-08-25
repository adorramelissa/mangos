/*
 *  EventPlayerInstanceMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventPlayerInstanceMgr.h"
#include "Policies/SingletonImp.h"
#include "Player.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerInstance>);
EventDebugPlayerInstance eventDebugPlayerInstance;

void EventDebugPlayerInstance::EventPlayerInstanceEntered(const EventInfoPlayerInstance &info)
{
    EVENTLOG("EventPlayerInstanceEntered - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerInstance::EventPlayerInstanceLeaved(const EventInfoPlayerInstance &info) 
{
    EVENTLOG("EventPlayerInstanceLeaved - id:%u", info.player.GetGUIDLow()); 
}

void EventDebugPlayerInstance::EventPlayerInstanceIdReceived(const EventInfoPlayerInstance &info) 
{
    EVENTLOG("EventPlayerInstanceIdReceived - id:%u", info.player.GetGUIDLow());
}
