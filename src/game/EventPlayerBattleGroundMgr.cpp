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

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerBattleGround>);
EventDebugPlayerBattleGround eventDebugPlayerBattleGround;

void EventDebugPlayerBattleGround::EventPlayerBattleGroundJoined(const EventInfoPlayerBattleGround &info)
{
    EVENTLOG("EventPlayerBattleGroundJoined - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerBattleGround::EventPlayerBattleGroundLeaved(const EventInfoPlayerBattleGround &info)
{
    EVENTLOG("EventPlayerBattleGroundLeaved - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerBattleGround::EventPlayerBattleGroundWon(const EventInfoPlayerBattleGround &info)
{
    EVENTLOG("EventPlayerBattleGroundWon - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerBattleGround::EventPlayerBattleGroundLost(const EventInfoPlayerBattleGround &info)
{
    EVENTLOG("EventPlayerBattleGroundLost - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerBattleGround::EventPlayerDuellWon(const EventInfoPlayerDuell &info)
{
    EVENTLOG("EventPlayerDuellWon - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerBattleGround::EventPlayerDuellLost(const EventInfoPlayerDuell &info)
{
    EVENTLOG("EventPlayerDuellLost - id:%u", info.player.GetGUIDLow());
}
