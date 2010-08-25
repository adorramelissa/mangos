/*
 *  EventPlayerLevelMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventPlayerLevelMgr.h"
#include "Policies/SingletonImp.h"
#include "Player.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerLevel>);
EventDebugPlayerLevel eventDebugPlayerLevel;

void EventDebugPlayerLevel::EventPlayerLevelReached(const EventInfoPlayerLevel &info) 
{
    EVENTLOG("EventPlayerLevelReached - id:%u, lvl:%u, inc:%d",
             info.player.GetGUIDLow(), info.level, info.increase); }

//void EventPlayerSkillLevelReached(const EventInfoPlayerLevel &info)
//{
//    EVENTLOG("EventPlayerSkillLevelReached - id:%u, lvl:%u, inc:%d",
//             info.player.GetGUIDLow(), info.level, info.increase);
//}

void EventDebugPlayerLevel::EventPlayerReputationLevelReached(const EventInfoPlayerLevel &info)
{
    EVENTLOG("EventPlayerReputationLevelReached - id:%u, lvl:%u, inc:%d",
             info.player.GetGUIDLow(), info.level, info.increase);
}

//void EventPlayerPersonalArenaRatingGained(const EventInfoPlayerLevel &info)
//{
//    EVENTLOG("EventPlayerPersonalArenaRatingGained - id:%u, lvl:%u, inc:%d",
//             info.player.GetGUIDLow(), info.level, info.increase); 
//}

void EventDebugPlayerLevel::EventPlayerTalentsReseted(const EventInfoPlayer &info)
{
    EVENTLOG("EventPlayerTalentsReseted - id:%u",
             info.player.GetGUIDLow()); 
}
