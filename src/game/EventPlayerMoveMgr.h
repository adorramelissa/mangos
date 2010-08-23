/*
 *  EventPlayerMoveMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTPLAYERMOVEMGR_H__
#define __EVENTPLAYERMOVEMGR_H__

#include "EventSystemMgr.h"
#include "EventPlayerDefines.h"

class Item;

struct EventInfoPlayerMove : public EventInfoPlayer
{
    // TODO: fill needed params

    EventInfoPlayerMove(const Player &player_)
    : EventInfoPlayer(player_) {}
};

class EventListenerPlayerMove : public EventListener
{
public:
    virtual void EventPlayerMoved(const EventInfoPlayerMove &) {}
    virtual void EventPlayerTeleported(const EventInfoPlayerMove &) {}
    virtual void EventPlayerFlightPathTaken(const EventInfoPlayerMove &) {}
};

// Debug purposes:
class EventDebugPlayerMove : public EventListenerPlayerMove
{
public:
    EventDebugPlayerMove()
    {
        sEventSystemMgr(EventListenerPlayerMove).RegisterListener(this);
    }
    void EventPlayerMoved(const EventInfoPlayerMove &) { sLog.outDebug("============EventPlayerMoved============"); }
    void EventPlayerTeleported(const EventInfoPlayerMove &) { sLog.outDebug("============EventPlayerTeleported============"); }
    void EventPlayerFlightPathTaken(const EventInfoPlayerMove &) { sLog.outDebug("============EventPlayerFlightPathTaken============"); }
};
extern EventDebugPlayerMove eventDebugPlayerMove;

#endif // __EVENTPLAYERMOVEMGR_H__
