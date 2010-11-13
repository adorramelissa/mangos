/*
 *  EventServerMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTSERVERMGR_H__
#define __EVENTSERVERMGR_H__

#include "EventSystemMgr.h"
#include "World.h"

struct EventInfoServer : public EventInfo
{
    ShutdownExitCode exitCode;

    EventInfoServer(ShutdownExitCode exitCode_)
    : EventInfo(), exitCode(exitCode_) {}
};

class EventListenerServer : public EventListener
{
public:
    virtual void EventServerStarted(const EventInfoServer &) {}
    virtual void EventServerStopped(const EventInfoServer &) {}
};

// Debug purposes:
#ifdef EVENTDEBUGOUT
class EventDebugServer : public EventListenerServer
{
public:
    EventDebugServer()
    {
        sEventSystemMgr(EventListenerServer).RegisterListener(this);
    }
    void EventServerStarted(const EventInfoServer &info);
    void EventServerStopped(const EventInfoServer &info);
};
extern EventDebugServer eventDebugServer;
#endif

#endif // __EVENTSERVERMGR_H__
