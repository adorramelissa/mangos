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

struct EventInfoBoss : public EventInfo
{
    const Creature &boss;

    EventInfoBoss(const Creature &boss_)
    : EventInfo(), boss(boss_) {}
};

class EventListenerBoss : public EventListener
{
public:
    virtual void EventBossAggroed(const EventInfoBoss &) {}
    virtual void EventBossDied(const EventInfoBoss &) {}
    virtual void EventBossEvaded(const EventInfoBoss &) {}
};

// Debug purposes:
class EventDebugBoss : public EventListenerBoss
{
public:
    EventDebugBoss()
    {
        sEventSystemMgr(EventListenerBoss).RegisterListener(this);
    }
    void EventBossAggroed(const EventInfoBoss &info);
    void EventBossDied(const EventInfoBoss &info);
    void EventBossEvaded(const EventInfoBoss &info);
};
extern EventDebugBoss eventDebugBoss;

#endif // __EVENTBOSSMGR_H__
