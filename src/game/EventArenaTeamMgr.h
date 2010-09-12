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

struct EventInfoArenaTeam : public EventInfo
{
    const ArenaTeam &team;

    EventInfoArenaTeam(const ArenaTeam &team_)
    : EventInfo(), team(team_) {}
};

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
#ifdef EVENTDEBUGOUT
class EventDebugArenaTeam : public EventListenerArenaTeam
{
public:
    EventDebugArenaTeam()
    {
        sEventSystemMgr(EventListenerArenaTeam).RegisterListener(this);
    }
    void EventArenaTeamCreated(const EventInfoArenaTeamStatus &info);
    void EventArenaTeamDisbanded(const EventInfoArenaTeamStatus &info);
    void EventArenaTeamRatingGained(const EventInfoArenaTeamRating &info);
};
extern EventDebugArenaTeam eventDebugArenaTeam;
#endif

#endif // __EVENTARENATEAMMGR_H__
