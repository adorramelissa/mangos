/*
 *  EventBossMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTBOSSMGR_H__
#define __EVENTBOSSMGR_H__

#include "EventSystemMgr.h"

class Creature;

typedef EventInfoSubject<Creature> EventInfoBoss;

class ListenerBoss : public Listener
{
public:
    virtual void EventBossAggroed(const EventInfoBoss &) {}
    virtual void EventBossDied(const EventInfoBoss &) {}
    virtual void EventBossEvaded(const EventInfoBoss &) {}
};

class EventBossMgr : public EventSystemMgr<ListenerBoss> {};

#define sEventBossMgr MaNGOS::Singleton<EventBossMgr>::Instance()

// Debug purposes:
class EventDebugBoss : public ListenerBoss
{
public:
    EventDebugBoss()
    {
        sEventBossMgr.Listener += this;
    }
    void EventBossAggroed(const EventInfoBoss &) { sLog.outDebug("============EventBossAggroed============"); }
    void EventBossDied(const EventInfoBoss &) { sLog.outDebug("============EventBossDied============"); }
    void EventBossEvaded(const EventInfoBoss &) { sLog.outDebug("============EventBossEvaded============"); }
};
extern EventDebugBoss eventDebugBoss;

#endif // __EVENTBOSSMGR_H__
