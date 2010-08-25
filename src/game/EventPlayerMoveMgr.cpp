/*
 *  EventPlayerMoveMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventPlayerMoveMgr.h"
#include "Policies/SingletonImp.h"
#include "Player.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerMove>);
EventDebugPlayerMove eventDebugPlayerMove;

void EventDebugPlayerMove::EventPlayerMoved(const EventInfoPlayerMove &info)
{
    EVENTLOG("EventPlayerMoved - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerMove::EventPlayerTeleported(const EventInfoPlayerMove &info)
{
    EVENTLOG("EventPlayerTeleported - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerMove::EventPlayerFlightPathTaken(const EventInfoPlayerMove &info)
{
    EVENTLOG("EventPlayerFlightPathTaken - id:%u", info.player.GetGUIDLow());
}

