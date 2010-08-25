/*
 *  EventArenaTeamMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventArenaTeamMgr.h"
#include "Policies/SingletonImp.h"
#include "ArenaTeam.h"
#include "Player.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerArenaTeam>);
EventDebugArenaTeam eventDebugArenaTeam;

void EventDebugArenaTeam::EventArenaTeamCreated(const EventInfoArenaTeamStatus &info)
{
    EVENTLOG("EventArenaTeamCreated - id:%u orig:%u", info.team.GetId(), info.originator->GetGUIDLow());
}

void EventDebugArenaTeam::EventArenaTeamDisbanded(const EventInfoArenaTeamStatus &info)
{
    EVENTLOG("EventArenaTeamDisbanded - id:%u orig:%u", info.team.GetId(), info.originator->GetGUIDLow());
}

void EventDebugArenaTeam::EventArenaTeamRatingGained(const EventInfoArenaTeamRating &info)
{
    EVENTLOG("EventArenaTeamRatingGained - id:%u amount:%d", info.team.GetId(), info.amount);
}