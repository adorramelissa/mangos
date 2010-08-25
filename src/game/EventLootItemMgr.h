/*
 *  EventLootItemMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTLOOTITEMMGR_H__
#define __EVENTLOOTITEMMGR_H__

#include "EventSystemMgr.h"

struct LootItem;
struct Loot;

struct EventInfoLootItem : public EventInfo
{
    const LootItem &item;
    const Loot &loot;

    EventInfoLootItem(const LootItem &item_, const Loot &loot_)
    : EventInfo(), item(item_), loot(loot_) {}
};

class EventListenerLootItem : public EventListener
{
public:
    virtual void EventLootItemColoredDropped(const EventInfoLootItem &) {}
    virtual void EventLootItemQuestDropped(const EventInfoLootItem &) {}
};

// Debug purposes:
class EventDebugLootItem : public EventListenerLootItem
{
public:
    EventDebugLootItem()
    {
        sEventSystemMgr(EventListenerLootItem).RegisterListener(this);
    }
    void EventLootItemColoredDropped(const EventInfoLootItem &info);
    void EventLootItemQuestDropped(const EventInfoLootItem &info);
};
extern EventDebugLootItem eventDebugLootItem;

#endif // __EVENTLOOTITEMMGR_H__
