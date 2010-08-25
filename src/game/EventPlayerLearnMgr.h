/*
 *  EventPlayerLearnMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTPLAYERLEARNMGR_H__
#define __EVENTPLAYERLEARNMGR_H__

#include "EventSystemMgr.h"
#include "EventPlayerDefines.h"

struct EventInfoPlayerLearn : public EventInfoPlayer
{
    // TODO: fill needed params

    EventInfoPlayerLearn(const Player &player_)
    : EventInfoPlayer(player_) {}
};

class EventListenerPlayerLearn : public EventListener
{
public:
    virtual void EventPlayerSpellLearned(const EventInfoPlayerLearn &) {}
};

// Debug purposes:
class EventDebugPlayerLearn : public EventListenerPlayerLearn
{
public:
    EventDebugPlayerLearn()
    {
        sEventSystemMgr(EventListenerPlayerLearn).RegisterListener(this);
    }
    void EventPlayerSpellLearned(const EventInfoPlayerLearn &info);
};
extern EventDebugPlayerLearn eventDebugPlayerLearn;

#endif // __EVENTPLAYERLEARNMGR_H__
