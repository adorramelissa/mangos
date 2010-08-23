/*
 *  EventArenaTeamMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTARENATEAMMGR_H__
#define __EVENTARENATEAMMGR_H__

#include "EventSystemMgr.h"

class Player;
class ArenaTeam;

typedef EventInfoSubject<ArenaTeam> EventInfoArenaTeam;

struct EventInfoArenaTeamStatus : public EventInfoArenaTeam
{
    const Player *originator;

    EventInfoArenaTeamStatus(const ArenaTeam &team_, const Player *originator_)
    : EventInfoArenaTeam(team_), originator(originator_) {}
};

struct EventInfoArenaTeamRating : public EventInfoArenaTeam
{
    uint32 amount;

    EventInfoArenaTeamRating(const ArenaTeam &team_, uint32 amount_)
    : EventInfoArenaTeam(team_), amount(amount_) {}
};

class EventListenerArenaTeam : public EventListener
{
public:
    virtual void EventArenaTeamCreated(const EventInfoArenaTeamStatus &) {}
    virtual void EventArenaTeamDisbanded(const EventInfoArenaTeamStatus &) {}
    virtual void EventArenaTeamRatingGained(const EventInfoArenaTeamRating &) {}
};

// Debug purposes:
class EventDebugArenaTeam : public EventListenerArenaTeam
{
public:
    EventDebugArenaTeam()
    {
        sEventSystemMgr(EventListenerArenaTeam).RegisterListener(this);
    }
    void EventArenaTeamCreated(const EventInfoArenaTeamStatus &) { sLog.outDebug("============EventArenaTeamCreated============"); }
    void EventArenaTeamDisbanded(const EventInfoArenaTeamStatus &) { sLog.outDebug("============EventArenaTeamDisbanded============"); }
    void EventArenaTeamRatingGained(const EventInfoArenaTeamRating &) { sLog.outDebug("============EventArenaTeamRatingGained============"); }
};
extern EventDebugArenaTeam eventDebugArenaTeam;

#endif // __EVENTARENATEAMMGR_H__
