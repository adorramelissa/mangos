/*
 *  EventCreatureMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTCREATUREMGR_H__
#define __EVENTCREATUREMGR_H__

#include "EventSystemMgr.h"

class Creature;

typedef EventInfoSubject<Creature> EventInfoCreature;

class EventListenerCreature : public EventListener
{
public:
    virtual void EventCreatureSpawned(const EventInfoCreature &) {}
    virtual void EventCreatureDied(const EventInfoCreature &) {}
};

// Debug purposes:
class EventDebugCreature : public EventListenerCreature
{
public:
    EventDebugCreature()
    {
        sEventSystemMgr(EventListenerCreature).RegisterListener(this);
    }
    void EventCreatureSpawned(const EventInfoCreature &) { sLog.outDebug("============EventCreatureSpawned============"); }
    void EventCreatureDied(const EventInfoCreature &) { sLog.outDebug("============EventCreatureDied============"); }
};
extern EventDebugCreature eventDebugCreature;

#endif // __EVENTCREATUREMGR_H__
