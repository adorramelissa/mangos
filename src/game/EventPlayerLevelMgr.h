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

class Player;

typedef EventInfoSubject<Player> EventInfoPlayer;

struct EventInfoPlayerLevel : public EventInfoPlayer
{
    uint32 level, increase;

    EventInfoPlayerLevel(const Player &player_, uint32 level_, uint32 increase_)
    : EventInfoPlayer(player_), level(level_), increase(increase_) {}
};

class ListenerPlayerLevel : public Listener
{
public:
    virtual void EventPlayerLevelReached(const EventInfoPlayerLevel &) {}
    //    virtual void EventPlayerSkillLevelReached(const EventInfoPlayerLevel &) {}
    virtual void EventPlayerReputationLevelReached(const EventInfoPlayerLevel &) {}
    //    virtual void EventPlayerPersonalArenaRatingGained(const EventInfoPlayerLevel &) {}
    virtual void EventPlayerTalentsReseted(const EventInfoPlayer &) {}
};

class EventPlayerLevelMgr : public EventSystemMgr<ListenerPlayerLevel> {};

#define sEventPlayerLevelMgr MaNGOS::Singleton<EventPlayerLevelMgr>::Instance()

// Debug purposes:
class EventDebugPlayerLevel : public ListenerPlayerLevel
{
public:
    EventDebugPlayerLevel()
    {
        sEventPlayerLevelMgr.Listener += this;
    }
    void EventPlayerLevelReached(const EventInfoPlayerLevel &) { sLog.outDebug("============EventPlayerLevelReached============"); }
    //    void EventPlayerSkillLevelReached(const EventInfoPlayerLevel &) { sLog.outDebug("============EventPlayerSkillLevelReached============"); }
    void EventPlayerReputationLevelReached(const EventInfoPlayerLevel &) { sLog.outDebug("============EventPlayerReputationLevelReached============"); }
    //    void EventPlayerPersonalArenaRatingGained(const EventInfoPlayerLevel &) { sLog.outDebug("============EventPlayerPersonalArenaRatingGained============"); }
    void EventPlayerTalentsReseted(const EventInfoPlayer &) { sLog.outDebug("============EventPlayerTalentsReseted============"); }
};
extern EventDebugPlayerLevel eventDebugPlayerLevel;

#endif // __EVENTPLAYERLEVELMGR_H__
