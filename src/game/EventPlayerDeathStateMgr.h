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

struct EventInfoPlayerDeathState : public EventInfoPlayer
{
    // TODO: fill needed params

    EventInfoPlayerDeathState(const Player &player_)
    : EventInfoPlayer(player_) {}
};

class EventListenerPlayerDeathState : public EventListener
{
public:
    virtual void EventPlayerRevived(const EventInfoPlayerDeathState &) {}
    virtual void EventPlayerDied(const EventInfoPlayerDeathState &) {}
};

// Debug purposes:
class EventDebugPlayerDeathState : public EventListenerPlayerDeathState
{
public:
    EventDebugPlayerDeathState()
    {
        sEventSystemMgr(EventListenerPlayerDeathState).RegisterListener(this);
    }
    void EventPlayerRevived(const EventInfoPlayerDeathState &info);
    void EventPlayerDied(const EventInfoPlayerDeathState &info);
};
extern EventDebugPlayerDeathState eventDebugPlayerDeathState;

#endif // __EVENTPLAYERDEATHSTATEMGR_H__
