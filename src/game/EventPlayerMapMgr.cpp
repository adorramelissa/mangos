/*
 *  EventPlayerMapMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventPlayerMapMgr.h"
#include "Policies/SingletonImp.h"
#include "Player.h"
#include "Map.h"
#include "InstanceSaveMgr.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerMap>);
EventDebugPlayerMap eventDebugPlayerMap;

void EventDebugPlayerMap::EventPlayerMapChanged(const EventInfoPlayerMap &info)
{
    EVENTLOG("EventPlayerMapChanged - id:%u map:%u oldmap:%u",
             info.player.GetGUIDLow(), info.map.MapID, info.oldmap.GetId());
}

void EventDebugPlayerMap::EventPlayerDungeonEntered(const EventInfoPlayerMap &info)
{
    EVENTLOG("EventPlayerDungeonEntered - id:%u map:%u oldmap:%u",
             info.player.GetGUIDLow(), info.map.MapID, info.oldmap.GetId());
}

void EventDebugPlayerMap::EventPlayerDungeonLeaved(const EventInfoPlayerMap &info)
{
    EVENTLOG("EventPlayerDungeonLeaved - id:%u map:%u oldmap:%u",
             info.player.GetGUIDLow(), info.map.MapID, info.oldmap.GetId());
}

void EventDebugPlayerMap::EventPlayerInstanceBound(const EventInfoPlayerInstance &info)
{
    EVENTLOG("EventPlayerInstanceBound - id:%u instance:%u",
             info.player.GetGUIDLow(), info.instance.GetInstanceId());
}
