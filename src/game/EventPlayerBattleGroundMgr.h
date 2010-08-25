/*
 *  EventPlayerBattleGroundMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTPLAYERBATTLEGROUNDMGR_H__
#define __EVENTPLAYERBATTLEGROUNDMGR_H__

#include "EventSystemMgr.h"
#include "EventPlayerDefines.h"

struct EventInfoPlayerBattleGround : public EventInfoPlayer
{
    // TODO: fill needed params
    
    EventInfoPlayerBattleGround(const Player &player_)
    : EventInfoPlayer(player_) {}
};

struct EventInfoPlayerDuell : public EventInfoPlayer
{
    // TODO: fill needed params
    
    EventInfoPlayerDuell(const Player &player_)
    : EventInfoPlayer(player_) {}
};

class EventListenerPlayerBattleGround : public EventListener
{
public:
    virtual void EventPlayerBattleGroundJoined(const EventInfoPlayerBattleGround &) {}
    virtual void EventPlayerBattleGroundLeaved(const EventInfoPlayerBattleGround &) {}
    virtual void EventPlayerBattleGroundWon(const EventInfoPlayerBattleGround &) {}
    virtual void EventPlayerBattleGroundLost(const EventInfoPlayerBattleGround &) {}
    virtual void EventPlayerDuellWon(const EventInfoPlayerDuell &) {}
    virtual void EventPlayerDuellLost(const EventInfoPlayerDuell &) {}
};

// Debug purposes:
class EventDebugPlayerBattleGround : public EventListenerPlayerBattleGround
{
public:
    EventDebugPlayerBattleGround()
    {
        sEventSystemMgr(EventListenerPlayerBattleGround).RegisterListener(this);
    }
    void EventPlayerBattleGroundJoined(const EventInfoPlayerBattleGround &info);
    void EventPlayerBattleGroundLeaved(const EventInfoPlayerBattleGround &info);
    void EventPlayerBattleGroundWon(const EventInfoPlayerBattleGround &info);
    void EventPlayerBattleGroundLost(const EventInfoPlayerBattleGround &info);
    void EventPlayerDuellWon(const EventInfoPlayerDuell &info);
    void EventPlayerDuellLost(const EventInfoPlayerDuell &info);
};
extern EventDebugPlayerBattleGround eventDebugPlayerBattleGround;

#endif // __EVENTPLAYERBATTLEGROUNDMGR_H__
