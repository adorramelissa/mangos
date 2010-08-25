/*
 *  EventPlayerTradeMgr.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTPLAYERTRADEMGR_H__
#define __EVENTPLAYERTRADEMGR_H__

#include "EventSystemMgr.h"
#include "EventPlayerDefines.h"

struct EventInfoPlayerTrade : public EventInfoPlayer
{
    // TODO: fill needed params

    EventInfoPlayerTrade(const Player &player_)
    : EventInfoPlayer(player_) {}
};

class EventListenerPlayerTrade : public EventListener
{
public:
    virtual void EventPlayerMailSend(const EventInfoPlayerTrade &) {}
    virtual void EventPlayerTradeAccepted(const EventInfoPlayerTrade &) {}
    virtual void EventPlayerTradeSpecialAccepted(const EventInfoPlayerTrade &) {}
    virtual void EventPlayerMerchantTraded(const EventInfoPlayerTrade &) {}
};

// Debug purposes:
class EventDebugPlayerTrade : public EventListenerPlayerTrade
{
public:
    EventDebugPlayerTrade()
    {
        sEventSystemMgr(EventListenerPlayerTrade).RegisterListener(this);
    }
    void EventPlayerMailSend(const EventInfoPlayerTrade &info);
    void EventPlayerTradeAccepted(const EventInfoPlayerTrade &info);
    void EventPlayerTradeSpecialAccepted(const EventInfoPlayerTrade &info);
    void EventPlayerMerchantTraded(const EventInfoPlayerTrade &info);
};
extern EventDebugPlayerTrade eventDebugPlayerTrade;

#endif // __EVENTPLAYERTRADEMGR_H__
