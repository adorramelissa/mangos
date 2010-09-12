/*
 *  EventPlayerLevelMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTPLAYERLEVELMGR_H__
#define __EVENTPLAYERLEVELMGR_H__

#include "EventSystemMgr.h"
#include "EventPlayerDefines.h"

struct EventInfoPlayerLevel : public EventInfoPlayer
{
    uint32 level, increase;

    EventInfoPlayerLevel(const Player &player_, uint32 level_, uint32 increase_)
    : EventInfoPlayer(player_), level(level_), increase(increase_) {}
};

class EventListenerPlayerLevel : public EventListener
{
public:
    virtual void EventPlayerLevelReached(const EventInfoPlayerLevel &) {}
    //    virtual void EventPlayerSkillLevelReached(const EventInfoPlayerLevel &) {}
    virtual void EventPlayerReputationLevelReached(const EventInfoPlayerLevel &) {}
    //    virtual void EventPlayerPersonalArenaRatingGained(const EventInfoPlayerLevel &) {}
    virtual void EventPlayerTalentsReseted(const EventInfoPlayer &) {}
};

// Debug purposes:
#ifdef EVENTDEBUGOUT
class EventDebugPlayerLevel : public EventListenerPlayerLevel
{
public:
    EventDebugPlayerLevel()
    {
        sEventSystemMgr(EventListenerPlayerLevel).RegisterListener(this);
    }
    void EventPlayerLevelReached(const EventInfoPlayerLevel &info);
//    void EventPlayerSkillLevelReached(const EventInfoPlayerLevel &info);
    void EventPlayerReputationLevelReached(const EventInfoPlayerLevel &info);
//    void EventPlayerPersonalArenaRatingGained(const EventInfoPlayerLevel &info);
    void EventPlayerTalentsReseted(const EventInfoPlayer &info);
};
extern EventDebugPlayerLevel eventDebugPlayerLevel;
#endif

#endif // __EVENTPLAYERLEVELMGR_H__
