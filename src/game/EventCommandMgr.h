/*
 *  EventCommandMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTCOMMANDMGR_H__
#define __EVENTCOMMANDMGR_H__

#include "EventSystemMgr.h"

class ChatCommand;
class Player;

struct EventInfoCommand : public EventInfo
{
    const ChatCommand &command;
    uint32 accountId;
    const Player *player;

    EventInfoCommand(const ChatCommand &command_, uint32 accountId_, const Player *player_)
    : EventInfo(), command(command_), accountId(accountId_), player(player_) {}
};

class EventListenerCommand : public EventListener
{
public:
    virtual void EventCommandUsed(const EventInfoCommand &) {}
    virtual void EventCommandGMUsed(const EventInfoCommand &) {}
};

// Debug purposes:
#ifdef EVENTDEBUGOUT
class EventDebugCommand : public EventListenerCommand
{
public:
    EventDebugCommand()
    {
        sEventSystemMgr(EventListenerCommand).RegisterListener(this);
    }
    void EventCommandUsed(const EventInfoCommand &info);
    void EventCommandGMUsed(const EventInfoCommand &info);
};
extern EventDebugCommand eventDebugCommand;
#endif

#endif // __EVENTCOMMANDMGR_H__
