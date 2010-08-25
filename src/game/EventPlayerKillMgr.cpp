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

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerKill>);
EventDebugPlayerKill eventDebugPlayerKill;

void EventDebugPlayerKill::EventPlayerKilledByPlayer(const EventInfoPlayerKill &info)
{
    EVENTLOG("EventPlayerKilledByPlayer - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerKill::EventPlayerKilledByCreature(const EventInfoPlayerKill &info)
{
    EVENTLOG("EventPlayerKilledByCreature - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerKill::EventPlayerKilledOtherPlayer(const EventInfoPlayerKill &info)
{
    EVENTLOG("EventPlayerKilledOtherPlayer - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerKill::EventPlayerKilledOtherCreature(const EventInfoPlayerKill &info)
{
    EVENTLOG("EventPlayerKilledOtherCreature - id:%u", info.player.GetGUIDLow());
}
