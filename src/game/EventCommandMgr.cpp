/*
 *  EventCommandMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventCommandMgr.h"
#include "Policies/SingletonImp.h"
#include "Chat.h"
#include "WorldPacket.h"
#include "Player.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerCommand>);

#ifdef EVENTDEBUGOUT
EventDebugCommand eventDebugCommand;

void EventDebugCommand::EventCommandUsed(const EventInfoCommand &info)
{
    EVENTLOG("EventCommandUsed - command:%s accid:%u player:%u",
             info.command.Name, info.accountId, info.player ? info.player->GetGUIDLow() : 0);
}

void EventDebugCommand::EventCommandGMUsed(const EventInfoCommand &info)
{
    EVENTLOG("EventCommandGMUsed - command:%s accid:%u player:%u",
             info.command.Name, info.accountId, info.player ? info.player->GetGUIDLow() : 0);
}
#endif
