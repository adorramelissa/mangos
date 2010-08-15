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

class Player;
class Item;

typedef EventInfoSubject<Player> EventInfoPlayer;

struct EventInfoPlayerItem : public EventInfoPlayer
{
    const Item &item;
    uint16 position;

    EventInfoPlayerItem(const Player &player_, const Item &item_, uint16 position_)
    : EventInfoPlayer(player_), item(item_), position(position_) {}
};

class ListenerPlayerItem : public Listener
{
public:
    virtual void EventPlayerItemUsed(const EventInfoPlayerItem &) {}
    virtual void EventPlayerItemEquipped(const EventInfoPlayerItem &) {}
    virtual void EventPlayerItemReceived(const EventInfoPlayerItem &) {}
    virtual void EventPlayerItemColoredReceived(const EventInfoPlayerItem &) {}
};

class EventPlayerItemMgr : public EventSystemMgr<ListenerPlayerItem> {};

#define sEventPlayerItemMgr MaNGOS::Singleton<EventPlayerItemMgr>::Instance()

// Debug purposes:
class EventDebugPlayerItem : public ListenerPlayerItem
{
public:
    EventDebugPlayerItem()
    {
        sEventPlayerItemMgr.Listener += this;
    }
    void EventPlayerItemUsed(const EventInfoPlayerItem &) { sLog.outDebug("============EventPlayerItemUsed============"); }
    void EventPlayerItemEquipped(const EventInfoPlayerItem &) { sLog.outDebug("============EventPlayerItemEquipped============"); }
    void EventPlayerItemReceived(const EventInfoPlayerItem &) { sLog.outDebug("============EventPlayerItemReceived============"); }
    void EventPlayerItemColoredReceived(const EventInfoPlayerItem &) { sLog.outDebug("============EventPlayerItemColoredReceived============"); }
};
extern EventDebugPlayerItem eventDebugPlayerItem;

#endif // __EVENTPLAYERITEMMGR_H__
