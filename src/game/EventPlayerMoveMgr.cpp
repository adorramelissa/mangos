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
#include "DBCStructure.h"
#include "Creature.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerMove>);
EventDebugPlayerMove eventDebugPlayerMove;

void EventDebugPlayerMove::EventPlayerMoved(const EventInfoPlayerMoveType &info)
{
    EVENTLOG("EventPlayerMoved - id:%u opcode:%d", info.player.GetGUIDLow(), info.opcode);
}

void EventDebugPlayerMove::EventPlayerTeleported(const EventInfoPlayerMoveTeleported &info)
{
    EVENTLOG("EventPlayerTeleported - id:%u type:%d", info.player.GetGUIDLow(), info.type);
}

void EventDebugPlayerMove::EventPlayerFlightPathTaken(const EventInfoPlayerMoveFlightPath &info)
{
    EVENTLOG("EventPlayerFlightPathTaken - id:%u from:%u to:%u npc:%u",
             info.player.GetGUIDLow(), info.source.ID, info.destination.ID, info.npc ? info.npc->GetGUIDLow() : 0);
}

