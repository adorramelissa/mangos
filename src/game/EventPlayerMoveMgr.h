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
#include "Opcodes.h"

struct TaxiNodesEntry;
class Creature;

enum EVENT_TELEPORTED_TYPE
{
    TELE_HEARTHSTONE,   // Homebind used
    TELE_AREATRIGGER,   // Stepped on areatrigger that teleports, also instance portals
    TELE_SPELL,         // Casted spell that teleports (Teleport: Stormwind)
    TELE_SPELL_UNKNOWN, // Unknown spell with teleportation ability
    TELE_LEAP,          // Casted spell that leaps (Blink, Charge)
    TELE_COMMAND,       // Used .go or .tele
    TELE_UNSTUCK,       // Unstuck spell?
    TELE_UNKNOWN        // Unknown reason for teleportation (pls report if happened)
};

struct EventInfoPlayerMoveType : public EventInfoPlayer
{   
    uint32 opcode;
    
    EventInfoPlayerMoveType(const Player &player_, uint32 opcode_)
    : EventInfoPlayer(player_), opcode(opcode_) {}
};

struct EventInfoPlayerMoveTeleported : public EventInfoPlayer
{
    EVENT_TELEPORTED_TYPE type;
    const void *data;
    
    EventInfoPlayerMoveTeleported(const Player &player_, EVENT_TELEPORTED_TYPE type_, const void *data_)
    : EventInfoPlayer(player_), type(type_), data(data_) {}
};

struct EventInfoPlayerMoveFlightPath : public EventInfoPlayer
{
    const TaxiNodesEntry &source, &destination;
    const Creature *npc;
    
    EventInfoPlayerMoveFlightPath(const Player &player_, const TaxiNodesEntry &source_, const TaxiNodesEntry &destination_, const Creature *npc_)
    : EventInfoPlayer(player_), source(source_), destination(destination_), npc(npc_) {}
};

class EventListenerPlayerMove : public EventListener
{
public:
    virtual void EventPlayerMoved(const EventInfoPlayerMoveType &) {}
    virtual void EventPlayerTeleported(const EventInfoPlayerMoveTeleported &) {}
    virtual void EventPlayerFlightPathTaken(const EventInfoPlayerMoveFlightPath &) {}
};

// Debug purposes:
class EventDebugPlayerMove : public EventListenerPlayerMove
{
public:
    EventDebugPlayerMove()
    {
        sEventSystemMgr(EventListenerPlayerMove).RegisterListener(this);
    }
    void EventPlayerMoved(const EventInfoPlayerMoveType &info);
    void EventPlayerTeleported(const EventInfoPlayerMoveTeleported &info);
    void EventPlayerFlightPathTaken(const EventInfoPlayerMoveFlightPath &info);
};
extern EventDebugPlayerMove eventDebugPlayerMove;

#endif // __EVENTPLAYERMOVEMGR_H__
