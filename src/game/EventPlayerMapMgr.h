/*
 *  EventPlayerMapMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTPLAYERMAPMGR_H__
#define __EVENTPLAYERMAPMGR_H__

#include "EventSystemMgr.h"
#include "EventPlayerDefines.h"

class Map;
class InstanceSave;

struct EventInfoPlayerMap : public EventInfoPlayer
{
    uint32 mapId, oldMapId;

    EventInfoPlayerMap(const Player &player_, const uint32 mapId_, const uint32 oldMapId_)
    : EventInfoPlayer(player_), mapId(mapId_), oldMapId(oldMapId_) {}
};

struct EventInfoPlayerInstance : public EventInfoPlayer
{
    const InstanceSave &instance;

    EventInfoPlayerInstance(const Player &player_, const InstanceSave &instance_)
    : EventInfoPlayer(player_), instance(instance_) {}
};

class EventListenerPlayerMap : public EventListener
{
public:
    virtual void EventPlayerMapChanged(const EventInfoPlayerMap &) {}
    virtual void EventPlayerDungeonEntered(const EventInfoPlayerMap &) {}
    virtual void EventPlayerDungeonLeaved(const EventInfoPlayerMap &) {}
    virtual void EventPlayerInstanceBound(const EventInfoPlayerInstance &) {}
};

// Debug purposes:
#ifdef EVENTDEBUGOUT
class EventDebugPlayerMap : public EventListenerPlayerMap
{
public:
    EventDebugPlayerMap()
    {
        sEventSystemMgr(EventListenerPlayerMap).RegisterListener(this);
    }
    void EventPlayerMapChanged(const EventInfoPlayerMap &info);
    void EventPlayerDungeonEntered(const EventInfoPlayerMap &);
    void EventPlayerDungeonLeaved(const EventInfoPlayerMap &);
    void EventPlayerInstanceBound(const EventInfoPlayerInstance &info);
};
extern EventDebugPlayerMap eventDebugPlayerMap;
#endif

#endif // __EVENTPLAYERMAPMGR_H__
