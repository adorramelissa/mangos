/*
 *  EventPlayerActionMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTPLAYERACTIONMGR_H__
#define __EVENTPLAYERACTIONMGR_H__

#include "EventSystemMgr.h"
#include "EventPlayerDefines.h"

struct EventInfoPlayerActionSpell : public EventInfoPlayer
{
    // TODO: fill needed params

    EventInfoPlayerActionSpell(const Player &player_)
    : EventInfoPlayer(player_) {}
};

struct EventInfoPlayerActionDamage : public EventInfoPlayer
{
    // TODO: fill needed params

    EventInfoPlayerActionDamage(const Player &player_)
    : EventInfoPlayer(player_) {}
};

class EventListenerPlayerAction : public EventListener
{
public:
    virtual void EventPlayerSpellCasted(const EventInfoPlayerActionSpell &) {}
    virtual void EventPlayerDamageDealt(const EventInfoPlayerActionDamage &) {}
};

// Debug purposes:
class EventDebugPlayerAction : public EventListenerPlayerAction
{
public:
    EventDebugPlayerAction()
    {
        sEventSystemMgr(EventListenerPlayerAction).RegisterListener(this);
    }
    void EventPlayerSpellCasted(const EventInfoPlayerActionSpell &info);
    void EventPlayerDamageDealt(const EventInfoPlayerActionDamage &info);
};
extern EventDebugPlayerAction eventDebugPlayerAction;

#endif // __EVENTPLAYERACTIONMGR_H__
