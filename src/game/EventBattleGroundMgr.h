/*
 *  EventBattleGroundMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTBATTLEGROUNDMGR_H__
#define __EVENTBATTLEGROUNDMGR_H__

#include "EventSystemMgr.h"

class BattleGround;
class ArenaTeam;

struct EventInfoBattleGround : public EventInfo
{
    const BattleGround &battleGround;
    const ArenaTeam *alliance, *horde;

    EventInfoBattleGround(const BattleGround &battleGround_, const ArenaTeam *alliance_, const ArenaTeam *horde_)
    : EventInfo(), battleGround(battleGround_), alliance(alliance_), horde(horde_) {}
};

struct EventInfoBattleGroundEnded : public EventInfoBattleGround
{
    uint32 winnerFaction;

    EventInfoBattleGroundEnded(const BattleGround &battleGround_, uint32 winnerFaction_,
                               const ArenaTeam *alliance_, const ArenaTeam *horde_)
    : EventInfoBattleGround(battleGround_, alliance_, horde_), winnerFaction(winnerFaction_) {}
};

class ListenerBattleGround : public Listener
{
public:
    virtual void EventBattleGroundStarted(const EventInfoBattleGround &) {}
    virtual void EventBattleGroundEnded(const EventInfoBattleGroundEnded &) {}
};

class EventBattleGroundMgr : public EventSystemMgr<ListenerBattleGround> {};

#define sEventBattleGroundMgr MaNGOS::Singleton<EventBattleGroundMgr>::Instance()

// Debug purposes:
class EventDebugBattleGround : public ListenerBattleGround
{
public:
    EventDebugBattleGround()
    {
        sEventBattleGroundMgr.Listener += this;
    }
    void EventBattleGroundStarted(const EventInfoBattleGround &) { sLog.outDebug("============EventBattleGroundStarted============"); }
    void EventBattleGroundEnded(const EventInfoBattleGroundEnded &) { sLog.outDebug("============EventBattleGroundEnded============"); }
};
extern EventDebugBattleGround eventDebugBattleGround;

#endif // __EVENTBATTLEGROUNDMGR_H__
