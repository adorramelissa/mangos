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

class MailDraft;
class TradeData;
class Creature;
class Item;

struct EventInfoPlayerTradeMail : public EventInfoPlayer
{
    const MailDraft &mail;
    uint64 recipient;

    EventInfoPlayerTradeMail(const Player &player_, const MailDraft &mail_, uint64 recipient_)
    : EventInfoPlayer(player_), mail(mail_), recipient(recipient_) {}
};

struct EventInfoPlayerTradeTrade : public EventInfoPlayer
{
    const Player &other;
    const TradeData &selfTrade, &otherTrade;
    bool specialTrade;

    EventInfoPlayerTradeTrade(const Player &player_, const Player &other_, const TradeData &selfTrade_, const TradeData &otherTrade_, bool specialTrade_ = false)
    : EventInfoPlayer(player_), other(other_), selfTrade(selfTrade_), otherTrade(otherTrade_), specialTrade(specialTrade_) {}
};

struct EventInfoPlayerTradeVendor : public EventInfoPlayer
{
    const Creature &vendor;
    const Item &item;
    uint32 count;

    EventInfoPlayerTradeVendor(const Player &player_, const Creature &vendor_, const Item &item_, uint32 count_)
    : EventInfoPlayer(player_), vendor(vendor_), item(item_), count(count_) {}
};

class EventListenerPlayerTrade : public EventListener
{
public:
    virtual void EventPlayerMailSend(const EventInfoPlayerTradeMail &) {}
    virtual void EventPlayerTradeAccepted(const EventInfoPlayerTradeTrade &) {}
    virtual void EventPlayerVendorTraded(const EventInfoPlayerTradeVendor &) {}
};

// Debug purposes:
#ifdef EVENTDEBUGOUT
class EventDebugPlayerTrade : public EventListenerPlayerTrade
{
public:
    EventDebugPlayerTrade()
    {
        sEventSystemMgr(EventListenerPlayerTrade).RegisterListener(this);
    }
    void EventPlayerMailSend(const EventInfoPlayerTradeMail &info);
    void EventPlayerTradeAccepted(const EventInfoPlayerTradeTrade &info);
    void EventPlayerVendorTraded(const EventInfoPlayerTradeVendor &info);
};
extern EventDebugPlayerTrade eventDebugPlayerTrade;
#endif

#endif // __EVENTPLAYERTRADEMGR_H__
