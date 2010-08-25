/*
 *  EventCharacterMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventCharacterMgr.h"
#include "Policies/SingletonImp.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerCharacter>);
EventDebugCharacter EventDebugCharacter;

void EventDebugCharacter::EventCharacterLogin(const EventInfoCharacter &info)
{
    EVENTLOG("EventCharacterLogin: char:%u name:%s accid:%u ip:%s",
             info.guid, info.name.c_str(), info.accountId, info.ip.c_str());
}

void EventDebugCharacter::EventCharacterLogout(const EventInfoCharacter &info)
{
    EVENTLOG("EventCharacterLogout: char:%u name:%s accid:%u ip:%s",
             info.guid, info.name.c_str(), info.accountId, info.ip.c_str());
}

void EventDebugCharacter::EventCharacterCreated(const EventInfoCharacter &info)
{
    EVENTLOG("EventCharacterCreated: char:%u name:%s accid:%u ip:%s",
             info.guid, info.name.c_str(), info.accountId, info.ip.c_str());
}

void EventDebugCharacter::EventCharacterRenamed(const EventInfoCharacterRenamed &info)
{
    EVENTLOG("EventCharacterRenamed: char:%u name:%s -> %s accid:%u ip:%s",
             info.guid, info.oldname.c_str(), info.name.c_str(), info.accountId, info.ip.c_str());
}

void EventDebugCharacter::EventCharacterDeleted(const EventInfoCharacter &info)
{
    EVENTLOG("EventCharacterDeleted: char:%u name:%s accid:%u ip:%s",
             info.guid, info.name.c_str(), info.accountId, info.ip.c_str());
}

void EventDebugCharacter::EventCharacterDeletedFinally(const EventInfoCharacter &info)
{
    EVENTLOG("EventCharacterDeletedFinally: char:%u name:%s accid:%u ip:%s",
             info.guid, info.name.c_str(), info.accountId, info.ip.c_str());
}
