/*
 *  EventPlayerQuestMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTPLAYERQUESTMGR_H__
#define __EVENTPLAYERQUESTMGR_H__

#include "EventSystemMgr.h"
#include "EventPlayerDefines.h"

struct EventInfoPlayerQuest : public EventInfoPlayer
{
    // TODO: fill needed params

    EventInfoPlayerQuest(const Player &player_)
    : EventInfoPlayer(player_) {}
};

class EventListenerPlayerQuest : public EventListener
{
public:
    virtual void EventPlayerQuestCompleted(const EventInfoPlayerQuest &) {}
    virtual void EventPlayerQuestAbandoned(const EventInfoPlayerQuest &) {}
    virtual void EventPlayerQuestItemCollected(const EventInfoPlayerQuest &) {}
};

// Debug purposes:
#ifdef EVENTDEBUGOUT
class EventDebugPlayerQuest : public EventListenerPlayerQuest
{
public:
    EventDebugPlayerQuest()
    {
        sEventSystemMgr(EventListenerPlayerQuest).RegisterListener(this);
    }
    void EventPlayerQuestCompleted(const EventInfoPlayerQuest &info);
    void EventPlayerQuestAbandoned(const EventInfoPlayerQuest &info);
    void EventPlayerQuestItemCollected(const EventInfoPlayerQuest &info);
};
extern EventDebugPlayerQuest eventDebugPlayerQuest;
#endif

#endif // __EVENTPLAYERQUESTMGR_H__
