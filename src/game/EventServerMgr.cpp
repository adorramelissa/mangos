/*
 *  EventServerMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventServerMgr.h"
#include "Policies/SingletonImp.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerServer>);

#ifdef EVENTDEBUGOUT
EventDebugServer eventDebugServer;

void EventDebugServer::EventServerStarted(const EventInfoServer &/*info*/)
{
    EVENTLOG("EventServerStarted");
}

void EventDebugServer::EventServerStopped(const EventInfoServer &info)
{
    EVENTLOG("EventServerStopped - reason:%u", info.exitCode);
}
#endif
