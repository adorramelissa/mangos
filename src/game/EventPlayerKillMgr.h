/*
 *  EventPlayerKillMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTPLAYERKILLMGR_H__
#define __EVENTPLAYERKILLMGR_H__

#include "EventSystemMgr.h"
#include "EventPlayerDefines.h"

class Item;

struct EventInfoPlayerKill : public EventInfoPlayer
{
    // TODO: fill needed params

    EventInfoPlayerKill(const Player &player_)
    : EventInfoPlayer(player_) {}
};

class EventListenerPlayerKill : public EventListener
{
public:
    virtual void EventPlayerKilledByPlayer(const EventInfoPlayerKill &) {}
    virtual void EventPlayerKilledByCreature(const EventInfoPlayerKill &) {}
    virtual void EventPlayerKilledOtherPlayer(const EventInfoPlayerKill &) {}
    virtual void EventPlayerKilledOtherCreature(const EventInfoPlayerKill &) {}
};

// Debug purposes:
class EventDebugPlayerKill : public EventListenerPlayerKill
{
public:
    EventDebugPlayerKill()
    {
        sEventSystemMgr(EventListenerPlayerKill).RegisterListener(this);
    }
    void EventPlayerKilledByPlayer(const EventInfoPlayerKill &) { sLog.outDebug("============EventPlayerKilledByPlayer============"); }
    void EventPlayerKilledByCreature(const EventInfoPlayerKill &) { sLog.outDebug("============EventPlayerKilledByCreature============"); }
    void EventPlayerKilledOtherPlayer(const EventInfoPlayerKill &) { sLog.outDebug("============EventPlayerKilledOtherPlayer============"); }
    void EventPlayerKilledOtherCreature(const EventInfoPlayerKill &) { sLog.outDebug("============EventPlayerKilledOtherCreature============"); }
};
extern EventDebugPlayerKill eventDebugPlayerKill;

#endif // __EVENTPLAYERKILLMGR_H__
