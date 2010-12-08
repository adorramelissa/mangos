/*
 *  EventBattleGroundMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventBattleGroundMgr.h"
#include "Policies/SingletonImp.h"
#include "BattleGround.h"
#include "ArenaTeam.h"
#include "ObjectGuid.h"
#include "Player.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerBattleGround>);

#ifdef EVENTDEBUGOUT
EventDebugBattleGround eventDebugBattleGround;

void EventDebugBattleGround::EventBattleGroundStarted(const EventInfoBattleGround &info)
{
    EVENTLOG("EventBattleGroundStarted - id:%u alliance:%u horde:%u",
             info.battleGround.GetInstanceID(), info.alliance ? info.alliance->GetId() : 0, info.horde ? info.horde->GetId() : 0);
}

void EventDebugBattleGround::EventBattleGroundEnded(const EventInfoBattleGroundEnded &info)
{
    EVENTLOG("EventBattleGroundEnded - id:%u alliance:%u horde:%u winner:%u change:%d",
             info.battleGround.GetInstanceID(), info.alliance ? info.alliance->GetId() : 0, info.horde ? info.horde->GetId() : 0,
             info.winnerFaction, info.ratingChange);
}
#endif
