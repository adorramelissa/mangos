/*
 *  EventPlayerInstanceMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTPLAYERINSTANCEMGR_H__
#define __EVENTPLAYERINSTANCEMGR_H__

#include "EventSystemMgr.h"
#include "EventPlayerDefines.h"

struct EventInfoPlayerInstance : public EventInfoPlayer
{
    // TODO: fill needed params

    EventInfoPlayerInstance(const Player &player_)
    : EventInfoPlayer(player_) {}
};

class EventListenerPlayerInstance : public EventListener
{
public:
    virtual void EventPlayerInstanceEntered(const EventInfoPlayerInstance &) {}
    virtual void EventPlayerInstanceLeaved(const EventInfoPlayerInstance &) {}
    virtual void EventPlayerInstanceIdReceived(const EventInfoPlayerInstance &) {}
};

// Debug purposes:
class EventDebugPlayerInstance : public EventListenerPlayerInstance
{
public:
    EventDebugPlayerInstance()
    {
        sEventSystemMgr(EventListenerPlayerInstance).RegisterListener(this);
    }
    void EventPlayerInstanceEntered(const EventInfoPlayerInstance &info);
    void EventPlayerInstanceLeaved(const EventInfoPlayerInstance &info);
    void EventPlayerInstanceIdReceived(const EventInfoPlayerInstance &info);
};
extern EventDebugPlayerInstance eventDebugPlayerInstance;

#endif // __EVENTPLAYERINSTANCEMGR_H__
