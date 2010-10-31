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

struct EventInfoLoot : public EventInfo
{
    const Loot &loot;
    const ObjectGuid &guid;
    const LootType type;
    
    EventInfoLoot(const Loot &loot_, const ObjectGuid &guid_, const LootType type_)
    : EventInfo(), loot(loot_), guid(guid_), type(type_) {}
};

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
    virtual void EventLootGenerated(const EventInfoLoot &) {}
    virtual void EventLootItemColoredDropped(const EventInfoLootItem &) {}
    virtual void EventLootItemQuestDropped(const EventInfoLootItem &) {}
};

// Debug purposes:
#ifdef EVENTDEBUGOUT
class EventDebugLootItem : public EventListenerLootItem
{
public:
    EventDebugLootItem()
    {
        sEventSystemMgr(EventListenerLootItem).RegisterListener(this);
    }
    void EventLootGenerated(const EventInfoLoot &);
    void EventLootItemColoredDropped(const EventInfoLootItem &info);
    void EventLootItemQuestDropped(const EventInfoLootItem &info);
};
extern EventDebugLootItem eventDebugLootItem;
#endif

#endif // __EVENTLOOTITEMMGR_H__
