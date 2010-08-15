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

class ListenerCommand : public Listener
{
public:
    virtual void EventCommandUsed(const EventInfoCommand &) {}
    virtual void EventCommandGMUsed(const EventInfoCommand &) {}
};

class EventCommandMgr : public EventSystemMgr<ListenerCommand> {};

#define sEventCommandMgr MaNGOS::Singleton<EventCommandMgr>::Instance()

// Debug purposes:
class EventDebugCommand : public ListenerCommand
{
public:
    EventDebugCommand()
    {
        sEventCommandMgr.Listener += this;
    }
    void EventCommandUsed(const EventInfoCommand &) { sLog.outDebug("============EventCommandUsed============"); }
    void EventCommandGMUsed(const EventInfoCommand &) { sLog.outDebug("============EventCommandGMUsed============"); }
};
extern EventDebugCommand eventDebugCommand;

#endif // __EVENTCOMMANDMGR_H__
