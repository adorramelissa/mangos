/*
 *  EventRaidMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTRAIDMGR_H__
#define __EVENTRAIDMGR_H__

#include "EventSystemMgr.h"

struct EventInfoRaid : public EventInfo
{
    // TODO: implement needed params

    EventInfoRaid()
    : EventInfo() {}
};

class EventListenerRaid : public EventListener
{
public:
    virtual void EventRaidCreated(const EventInfoRaid &) {}
    virtual void EventRaidDisbanded(const EventInfoRaid &) {}
};

// Debug purposes:
class EventDebugRaid : public EventListenerRaid
{
public:
    EventDebugRaid()
    {
        sEventSystemMgr(EventListenerRaid).RegisterListener(this);
    }
    void EventRaidCreated(const EventInfoRaid &) { sLog.outDebug("============EventRaidCreated============"); }
    void EventRaidDisbanded(const EventInfoRaid &) { sLog.outDebug("============EventRaidDisbanded============"); }
};
extern EventDebugRaid eventDebugRaid;

#endif // __EVENTRAIDMGR_H__
