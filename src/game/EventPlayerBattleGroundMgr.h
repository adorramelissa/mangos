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

class EventListenerPlayerBattleGround : public EventListener
{
public:
    virtual void EventPlayerBattleGroundJoined(const EventInfoPlayerBattleGround &) {}
    virtual void EventPlayerBattleGroundLeaved(const EventInfoPlayerBattleGround &) {}
    virtual void EventPlayerBattleGroundWon(const EventInfoPlayerBattleGround &) {}
    virtual void EventPlayerBattleGroundLost(const EventInfoPlayerBattleGround &) {}
    virtual void EventPlayerDuellWon(const EventInfoPlayerBattleGround &) {}
    virtual void EventPlayerDuellLost(const EventInfoPlayerBattleGround &) {}
};

// Debug purposes:
class EventDebugPlayerBattleGround : public EventListenerPlayerBattleGround
{
public:
    EventDebugPlayerBattleGround()
    {
        sEventSystemMgr(EventListenerPlayerBattleGround).RegisterListener(this);
    }
    void EventPlayerBattleGroundJoined(const EventInfoPlayerBattleGround &) { sLog.outDebug("============EventPlayerBattleGroundJoined============"); }
    void EventPlayerBattleGroundLeaved(const EventInfoPlayerBattleGround &) { sLog.outDebug("============EventPlayerBattleGroundLeaved============"); }
    void EventPlayerBattleGroundWon(const EventInfoPlayerBattleGround &) { sLog.outDebug("============EventPlayerBattleGroundWon============"); }
    void EventPlayerBattleGroundLost(const EventInfoPlayerBattleGround &) { sLog.outDebug("============EventPlayerBattleGroundLost============"); }
    void EventPlayerDuellWon(const EventInfoPlayerBattleGround &) { sLog.outDebug("============EventPlayerDuellWon============"); }
    void EventPlayerDuellLost(const EventInfoPlayerBattleGround &) { sLog.outDebug("============EventPlayerDuellLost============"); }
};
extern EventDebugPlayerBattleGround eventDebugPlayerBattleGround;

#endif // __EVENTPLAYERBATTLEGROUNDMGR_H__
