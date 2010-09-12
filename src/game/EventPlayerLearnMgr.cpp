/*
 *  EventPlayerLearnMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventPlayerLearnMgr.h"
#include "Policies/SingletonImp.h"
#include "Player.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerLearn>);

#ifdef EVENTDEBUGOUT
EventDebugPlayerLearn eventDebugPlayerLearn;

void EventDebugPlayerLearn::EventPlayerSpellLearned(const EventInfoPlayerLearn &info)
{
    EVENTLOG("EventPlayerSpellLearned - id:%u", info.player.GetGUIDLow());
}
#endif
