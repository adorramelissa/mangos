/*
 *  EventPlayerDeathStateMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTPLAYERDEATHSTATEMGR_H__
#define __EVENTPLAYERDEATHSTATEMGR_H__

#include "EventSystemMgr.h"
#include "EventPlayerDefines.h"
#include "SharedDefines.h"

enum EventReviveType {
    REVIVE_GRAVEYARD,
    REVIVE_CORPSE,
    REVIVE_SPELL,
    REVIVE_INSTANCE,
    REVIVE_BATTLEGROUND,
    REVIVE_TRANSPORT,
    REVIVE_COMMAND,
    REVIVE_OTHER
};

struct EventInfoPlayerDeath : public EventInfoPlayer
{
    DamageReasonType reason;

    EventInfoPlayerDeath(const Player &player_, DamageReasonType reason_)
    : EventInfoPlayer(player_), reason(reason_) {}
};

struct EventInfoPlayerRevive : public EventInfoPlayer
{
    EventReviveType reason;

    EventInfoPlayerRevive(const Player &player_, EventReviveType reason_)
    : EventInfoPlayer(player_), reason(reason_) {}
};

class EventListenerPlayerDeathState : public EventListener
{
public:
    virtual void EventPlayerRevived(const EventInfoPlayerRevive &) {}
    virtual void EventPlayerDied(const EventInfoPlayerDeath &) {}
};

// Debug purposes:
class EventDebugPlayerDeathState : public EventListenerPlayerDeathState
{
public:
    EventDebugPlayerDeathState()
    {
        sEventSystemMgr(EventListenerPlayerDeathState).RegisterListener(this);
    }
    void EventPlayerRevived(const EventInfoPlayerRevive &info);
    void EventPlayerDied(const EventInfoPlayerDeath &info);
};
extern EventDebugPlayerDeathState eventDebugPlayerDeathState;

#endif // __EVENTPLAYERDEATHSTATEMGR_H__
