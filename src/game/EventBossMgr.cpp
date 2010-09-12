/*
 *  EventBossMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventBossMgr.h"
#include "Policies/SingletonImp.h"
#include "Creature.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerBoss>);

#ifdef EVENTDEBUGOUT
EventDebugBoss eventDebugBoss;

void EventDebugBoss::EventBossAggroed(const EventInfoBoss &info)
{
    EVENTLOG("EventBossAggroed - guid:%u", info.boss.GetGUIDLow());
}

void EventDebugBoss::EventBossDied(const EventInfoBoss &info)
{
    EVENTLOG("EventBossDied - guid:%u", info.boss.GetGUIDLow());
}

void EventDebugBoss::EventBossEvaded(const EventInfoBoss &info)
{
    EVENTLOG("EventBossEvaded - guid:%u", info.boss.GetGUIDLow());
}
#endif
