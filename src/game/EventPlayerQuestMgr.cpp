/*
 *  EventPlayerQuestMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventPlayerQuestMgr.h"
#include "Policies/SingletonImp.h"
#include "Player.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerQuest>);

#ifdef EVENTDEBUGOUT
EventDebugPlayerQuest eventDebugPlayerQuest;

void EventDebugPlayerQuest::EventPlayerQuestCompleted(const EventInfoPlayerQuest &info)
{
    EVENTLOG("EventPlayerQuestCompleted - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerQuest::EventPlayerQuestAbandoned(const EventInfoPlayerQuest &info)
{
    EVENTLOG("EventPlayerQuestAbandoned - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerQuest::EventPlayerQuestItemCollected(const EventInfoPlayerQuest &info)
{
    EVENTLOG("EventPlayerQuestItemCollected - id:%u", info.player.GetGUIDLow());
}
#endif
