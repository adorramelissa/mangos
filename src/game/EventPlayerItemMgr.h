/*
 *  EventPlayerItemMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTPLAYERITEMMGR_H__
#define __EVENTPLAYERITEMMGR_H__

#include "EventSystemMgr.h"
#include "EventPlayerDefines.h"

class Item;

struct EventInfoPlayerItem : public EventInfoPlayer
{
    const Item &item;
    uint16 position;

    EventInfoPlayerItem(const Player &player_, const Item &item_, uint16 position_)
    : EventInfoPlayer(player_), item(item_), position(position_) {}
};

struct EventInfoPlayerMoney : public EventInfoPlayer
{
    uint32 amount;

    EventInfoPlayerMoney(const Player &player_, uint32 amount_)
    : EventInfoPlayer(player_), amount(amount_) {}
};

class EventListenerPlayerItem : public EventListener
{
public:
    virtual void EventPlayerItemUsed(const EventInfoPlayerItem &) {}
    virtual void EventPlayerItemEquipped(const EventInfoPlayerItem &) {}
    virtual void EventPlayerItemReceived(const EventInfoPlayerItem &) {}
    virtual void EventPlayerItemColoredReceived(const EventInfoPlayerItem &) {}
    virtual void EventPlayerMoneyGained(const EventInfoPlayerMoney &) {}
};

// Debug purposes:
class EventDebugPlayerItem : public EventListenerPlayerItem
{
public:
    EventDebugPlayerItem()
    {
        sEventSystemMgr(EventListenerPlayerItem).RegisterListener(this);
    }
    void EventPlayerItemUsed(const EventInfoPlayerItem &) { sLog.outDebug("============EventPlayerItemUsed============"); }
    void EventPlayerItemEquipped(const EventInfoPlayerItem &) { sLog.outDebug("============EventPlayerItemEquipped============"); }
    void EventPlayerItemReceived(const EventInfoPlayerItem &) { sLog.outDebug("============EventPlayerItemReceived============"); }
    void EventPlayerItemColoredReceived(const EventInfoPlayerItem &) { sLog.outDebug("============EventPlayerItemColoredReceived============"); }
    void EventPlayerMoneyGained(const EventInfoPlayerMoney &) { sLog.outDebug("============EventPlayerMoneyGained============"); }
};
extern EventDebugPlayerItem eventDebugPlayerItem;

#endif // __EVENTPLAYERITEMMGR_H__
