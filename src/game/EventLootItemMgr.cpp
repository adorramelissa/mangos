/*
 *  EventLootItemMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventLootItemMgr.h"
#include "Policies/SingletonImp.h"
#include "LootMgr.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerLootItem>);

#ifdef EVENTDEBUGOUT
EventDebugLootItem eventDebugLootItem;

void EventDebugLootItem::EventLootGenerated(const EventInfoLoot &info)
{
    EVENTLOG("EventLootItemColoredDropped - guid:%u", info.guid.GetEntry());
}

void EventDebugLootItem::EventLootItemColoredDropped(const EventInfoLootItem &info)
{
    EVENTLOG("EventLootItemColoredDropped - id:%u", info.item.itemid);
}

void EventDebugLootItem::EventLootItemQuestDropped(const EventInfoLootItem &info)
{
    EVENTLOG("EventLootItemQuestDropped - id:%u", info.item.itemid);
}
#endif
