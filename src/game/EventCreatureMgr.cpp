/*
 *  EventCreatureMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventCreatureMgr.h"
#include "Policies/SingletonImp.h"
#include "Creature.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerCreature>);

#ifdef EVENTDEBUGOUT
EventDebugCreature eventDebugCreature;

void EventDebugCreature::EventCreatureSpawned(const EventInfoCreature &info)
{
    EVENTLOG("EventCreatureSpawned - guid:%u", info.creature.GetGUIDLow());
}

void EventDebugCreature::EventCreatureDied(const EventInfoCreature &info)
{
    EVENTLOG("EventCreatureDied - guid:%u", info.creature.GetGUIDLow());
}
#endif
