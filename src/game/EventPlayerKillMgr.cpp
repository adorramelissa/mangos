/*
 *  EventPlayerKillMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventPlayerKillMgr.h"
#include "Policies/SingletonImp.h"
#include "Player.h"
#include "Unit.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerKill>);
EventDebugPlayerKill eventDebugPlayerKill;

void EventDebugPlayerKill::EventPlayerKilledByPlayer(const EventInfoPlayerKill &info)
{
    EVENTLOG("EventPlayerKilledByPlayer - id:%u enemy:%u", info.player.GetGUIDLow(), info.enemy.GetGUIDLow());
}

void EventDebugPlayerKill::EventPlayerKilledByCreature(const EventInfoPlayerKill &info)
{
    EVENTLOG("EventPlayerKilledByCreature - id:%u enemy:%u", info.player.GetGUIDLow(), info.enemy.GetGUIDLow());
}

void EventDebugPlayerKill::EventPlayerKilledOtherPlayer(const EventInfoPlayerKill &info)
{
    EVENTLOG("EventPlayerKilledOtherPlayer - id:%u enemy:%u", info.player.GetGUIDLow(), info.enemy.GetGUIDLow());
}

void EventDebugPlayerKill::EventPlayerKilledOtherCreature(const EventInfoPlayerKill &info)
{
    EVENTLOG("EventPlayerKilledOtherCreature - id:%u enemy:%u", info.player.GetGUIDLow(), info.enemy.GetGUIDLow());
}
