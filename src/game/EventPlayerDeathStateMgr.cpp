/*
 *  EventPlayerDeathStateMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventPlayerDeathStateMgr.h"
#include "Policies/SingletonImp.h"
#include "Player.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerDeathState>);
EventDebugPlayerDeathState eventDebugPlayerDeathState;

void EventDebugPlayerDeathState::EventPlayerRevived(const EventInfoPlayerDeathState &info)
{
    EVENTLOG("EventPlayerRevived - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerDeathState::EventPlayerDied(const EventInfoPlayerDeathState &info)
{
    EVENTLOG("EventPlayerDied - id:%u", info.player.GetGUIDLow());
}
