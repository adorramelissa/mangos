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

void EventDebugPlayerDeathState::EventPlayerRevived(const EventInfoPlayerRevive &info)
{
    EVENTLOG("EventPlayerRevived - id:%u reason:%u", info.player.GetGUIDLow(), info.reason);
}

void EventDebugPlayerDeathState::EventPlayerDied(const EventInfoPlayerDeath &info)
{
    EVENTLOG("EventPlayerDied - id:%u reason:%u", info.player.GetGUIDLow(), info.reason);
}
