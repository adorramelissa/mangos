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

class BattleGround;
class ObjectGuid;
class ArenaTeam;

struct EventInfoPlayerBattleGround : public EventInfoPlayer
{
    const BattleGround &battleGround;

    EventInfoPlayerBattleGround(const Player &player_, const BattleGround &battleGround_)
    : EventInfoPlayer(player_), battleGround(battleGround_) {}
};

struct EventInfoPlayerDuel : public EventInfoPlayer
{
    const Player &enemy;

    EventInfoPlayerDuel(const Player &player_, const Player &enemy_)
    : EventInfoPlayer(player_), enemy(enemy_) {}
};

struct EventInfoPlayerArenaTeam : public EventInfo
{
    const ObjectGuid &guid;
    const ArenaTeam &team;

    EventInfoPlayerArenaTeam(const ObjectGuid &guid_, const ArenaTeam &team_)
    : EventInfo(), guid(guid_), team(team_) {}
};

class EventListenerPlayerBattleGround : public EventListener
{
public:
    virtual void EventPlayerBattleGroundJoined(const EventInfoPlayerBattleGround &) {}
    virtual void EventPlayerBattleGroundLeft(const EventInfoPlayerBattleGround &) {}
    virtual void EventPlayerBattleGroundWon(const EventInfoPlayerBattleGround &) {}
    virtual void EventPlayerBattleGroundLost(const EventInfoPlayerBattleGround &) {}
    virtual void EventPlayerDuelWon(const EventInfoPlayerDuel &) {}
    virtual void EventPlayerDuelLost(const EventInfoPlayerDuel &) {}
    virtual void EventPlayerArenaTeamJoined(const EventInfoPlayerArenaTeam &) {}
    virtual void EventPlayerArenaTeamLeft(const EventInfoPlayerArenaTeam &) {}
};

// Debug purposes:
#ifdef EVENTDEBUGOUT
class EventDebugPlayerBattleGround : public EventListenerPlayerBattleGround
{
public:
    EventDebugPlayerBattleGround()
    {
        sEventSystemMgr(EventListenerPlayerBattleGround).RegisterListener(this);
    }
    void EventPlayerBattleGroundJoined(const EventInfoPlayerBattleGround &info);
    void EventPlayerBattleGroundLeft(const EventInfoPlayerBattleGround &info);
    void EventPlayerBattleGroundWon(const EventInfoPlayerBattleGround &info);
    void EventPlayerBattleGroundLost(const EventInfoPlayerBattleGround &info);
    void EventPlayerDuelWon(const EventInfoPlayerDuel &info);
    void EventPlayerDuelLost(const EventInfoPlayerDuel &info);
    void EventPlayerArenaTeamJoined(const EventInfoPlayerArenaTeam &info);
    void EventPlayerArenaTeamLeft(const EventInfoPlayerArenaTeam &info);
};
extern EventDebugPlayerBattleGround eventDebugPlayerBattleGround;
#endif

#endif // __EVENTPLAYERBATTLEGROUNDMGR_H__
