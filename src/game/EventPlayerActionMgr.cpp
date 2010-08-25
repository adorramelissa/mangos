/*
 *  EventPlayerActionMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventPlayerActionMgr.h"
#include "Policies/SingletonImp.h"
#include "Player.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerAction>);
EventDebugPlayerAction EventDebugPlayerAction;

void EventDebugPlayerAction::EventPlayerSpellCasted(const EventInfoPlayerActionSpell &info)
{
    EVENTLOG("EventPlayerSpellCasted - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerAction::EventPlayerDamageDealt(const EventInfoPlayerActionDamage &info)
{
    EVENTLOG("EventPlayerDamageDealt - id:%u", info.player.GetGUIDLow());
}
