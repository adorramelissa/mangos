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
    void EventPlayerKilledByPlayer(const EventInfoPlayerKill &info);
    void EventPlayerKilledByCreature(const EventInfoPlayerKill &info);
    void EventPlayerKilledOtherPlayer(const EventInfoPlayerKill &info);
    void EventPlayerKilledOtherCreature(const EventInfoPlayerKill &info);
};
extern EventDebugPlayerKill eventDebugPlayerKill;

#endif // __EVENTPLAYERKILLMGR_H__
