/*
 *  EventPlayerBattleGroundMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventPlayerBattleGroundMgr.h"
#include "Policies/SingletonImp.h"
#include "Player.h"
#include "ArenaTeam.h"
#include "ObjectGuid.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerBattleGround>);

#ifdef EVENTDEBUGOUT
EventDebugPlayerBattleGround eventDebugPlayerBattleGround;

void EventDebugPlayerBattleGround::EventPlayerBattleGroundJoined(const EventInfoPlayerBattleGround &info)
{
    EVENTLOG("EventPlayerBattleGroundJoined - id:%u bg:%u", info.player.GetGUIDLow(), info.battleGround.GetInstanceID());
}

void EventDebugPlayerBattleGround::EventPlayerBattleGroundLeaved(const EventInfoPlayerBattleGround &info)
{
    EVENTLOG("EventPlayerBattleGroundLeaved - id:%u bg:%u", info.player.GetGUIDLow(), info.battleGround.GetInstanceID());
}

void EventDebugPlayerBattleGround::EventPlayerBattleGroundWon(const EventInfoPlayerBattleGround &info)
{
    EVENTLOG("EventPlayerBattleGroundWon - id:%u bg:%u", info.player.GetGUIDLow(), info.battleGround.GetInstanceID());
}

void EventDebugPlayerBattleGround::EventPlayerBattleGroundLost(const EventInfoPlayerBattleGround &info)
{
    EVENTLOG("EventPlayerBattleGroundLost - id:%u bg:%u", info.player.GetGUIDLow(), info.battleGround.GetInstanceID());
}

void EventDebugPlayerBattleGround::EventPlayerDuelWon(const EventInfoPlayerDuel &info)
{
    EVENTLOG("EventPlayerDuelWon - id:%u enemy:%u", info.player.GetGUIDLow(), info.enemy.GetGUIDLow());
}

void EventDebugPlayerBattleGround::EventPlayerDuelLost(const EventInfoPlayerDuel &info)
{
    EVENTLOG("EventPlayerDuelLost - id:%u enemy:%u", info.player.GetGUIDLow(), info.enemy.GetGUIDLow());
}

void EventDebugPlayerBattleGround::EventPlayerArenaTeamJoined(const EventInfoPlayerArenaTeam &info)
{
    EVENTLOG("EventPlayerArenaTeamJoined - id:%u team:%u", info.guid.GetEntry(), info.team.GetId());
}

void EventDebugPlayerBattleGround::EventPlayerArenaTeamLeaved(const EventInfoPlayerArenaTeam &info)
{
    EVENTLOG("EventPlayerArenaTeamLeaved - id:%u team:%u", info.guid.GetEntry(), info.team.GetId());
}
#endif
