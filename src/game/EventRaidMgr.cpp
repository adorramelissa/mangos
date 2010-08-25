/*
 *  EventRaidMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventRaidMgr.h"
#include "Policies/SingletonImp.h"
#include "Group.h"
#include "Database/Field.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerRaid>);
EventDebugRaid eventDebugRaid;

void EventDebugRaid::EventRaidCreated(const EventInfoRaid &info)
{
    EVENTLOG("EventRaidCreated - id:%u", info.group.GetId()); 
}

void EventDebugRaid::EventRaidDisbanded(const EventInfoRaid &info)
{
    EVENTLOG("EventRaidDisbanded - id:%u", info.group.GetId());
}
