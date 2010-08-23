/*
 *  EventCharacterMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTCHARACTERMGR_H__
#define __EVENTCHARACTERMGR_H__

#include "EventSystemMgr.h"

struct EventInfoCharacter : public EventInfo
{
    uint32 guid;
    const std::string &name;
    uint32 accountId;
    const std::string &ip;

    EventInfoCharacter(uint32 guid_, const std::string &name_, uint32 accountId_, const std::string &ip_)
    : EventInfo(), guid(guid_), name(name_), accountId(accountId_), ip(ip_) {}
};

struct EventInfoCharacterRenamed : public EventInfoCharacter
{
    const std::string &oldname;

    EventInfoCharacterRenamed(uint32 guid_, const std::string &name_, const std::string &oldname_,
                              uint32 accountId_, const std::string &ip_)
    : EventInfoCharacter(guid_, name_, accountId_, ip_), oldname(oldname_) {}
};

class EventListenerCharacter : public EventListener
{
public:
    virtual void EventCharacterLogin(const EventInfoCharacter &) {}
    virtual void EventCharacterLogout(const EventInfoCharacter &) {}
    virtual void EventCharacterCreated(const EventInfoCharacter &) {}
    virtual void EventCharacterRenamed(const EventInfoCharacterRenamed &) {}
    virtual void EventCharacterDeleted(const EventInfoCharacter &) {}
    virtual void EventCharacterDeletedFinally(const EventInfoCharacter &) {}
};

// Debug purposes:
class EventDebugCharacter : public EventListenerCharacter
{
public:
    EventDebugCharacter()
    {
        sEventSystemMgr(EventListenerCharacter).RegisterListener(this);
    }
    void EventCharacterLogin(const EventInfoCharacter &) { sLog.outDebug("============EventCharacterLogin============"); }
    void EventCharacterLogout(const EventInfoCharacter &) { sLog.outDebug("============EventCharacterLogout============"); }
    void EventCharacterCreated(const EventInfoCharacter &) { sLog.outDebug("============EventCharacterCreated============"); }
    void EventCharacterRenamed(const EventInfoCharacterRenamed &) { sLog.outDebug("============EventCharacterRenamed============"); }
    void EventCharacterDeleted(const EventInfoCharacter &) { sLog.outDebug("============EventCharacterDeleted============"); }
    void EventCharacterDeletedFinally(const EventInfoCharacter &) { sLog.outDebug("============EventCharacterDeletedFinally============"); }
};
extern EventDebugCharacter eventDebugCharacter;

#endif // __EVENTCHARACTERMGR_H__
