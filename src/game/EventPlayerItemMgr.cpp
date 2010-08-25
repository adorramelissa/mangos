/*
 *  EventPlayerItemMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventPlayerItemMgr.h"
#include "Policies/SingletonImp.h"
#include "Player.h"
#include "Item.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerItem>);
EventDebugPlayerItem eventDebugPlayerItem;

void EventDebugPlayerItem::EventPlayerItemUsed(const EventInfoPlayerItem &info)
{
    EVENTLOG("EventPlayerItemUsed - id:%u, item:%u, bag:%u, slot:%u",
             info.player.GetGUIDLow(), info.item.GetGUIDLow(), info.position >> 8, info.position & 255);
}

void EventDebugPlayerItem::EventPlayerItemEquipped(const EventInfoPlayerItem &info)
{
    EVENTLOG("EventPlayerItemEquipped - id:%u, item:%u, bag:%u, slot:%u",
             info.player.GetGUIDLow(), info.item.GetGUIDLow(), info.position >> 8, info.position & 255);
}

void EventDebugPlayerItem::EventPlayerItemReceived(const EventInfoPlayerItem &info)
{
    EVENTLOG("EventPlayerItemReceived - id:%u, item:%u, bag:%u, slot:%u",
             info.player.GetGUIDLow(), info.item.GetGUIDLow(), info.position >> 8, info.position & 255);
}

void EventDebugPlayerItem::EventPlayerItemColoredReceived(const EventInfoPlayerItem &info)
{
    EVENTLOG("EventPlayerItemColoredReceived - id:%u, item:%u, bag:%u, slot:%u",
             info.player.GetGUIDLow(), info.item.GetGUIDLow(), info.position >> 8, info.position & 255);
}

void EventDebugPlayerItem::EventPlayerMoneyGained(const EventInfoPlayerMoney &info)
{
    EVENTLOG("EventPlayerMoneyGained - id:%u, amount:%d",
             info.player.GetGUIDLow(), info.amount); 
}
