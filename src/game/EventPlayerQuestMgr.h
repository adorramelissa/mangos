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

class Item;

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
class EventDebugPlayerQuest : public EventListenerPlayerQuest
{
public:
    EventDebugPlayerQuest()
    {
        sEventSystemMgr(EventListenerPlayerQuest).RegisterListener(this);
    }
    void EventPlayerQuestCompleted(const EventInfoPlayerQuest &) { sLog.outDebug("============EventPlayerQuestCompleted============"); }
    void EventPlayerQuestAbandoned(const EventInfoPlayerQuest &) { sLog.outDebug("============EventPlayerQuestAbandoned============"); }
    void EventPlayerQuestItemCollected(const EventInfoPlayerQuest &) { sLog.outDebug("============EventPlayerQuestItemCollected============"); }
};
extern EventDebugPlayerQuest eventDebugPlayerQuest;

#endif // __EVENTPLAYERQUESTMGR_H__
