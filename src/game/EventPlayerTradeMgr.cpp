/*
 *  EventPlayerTradeMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventPlayerTradeMgr.h"
#include "Policies/SingletonImp.h"
#include "Player.h"
#include "Creature.h"
#include "Item.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerTrade>);
EventDebugPlayerTrade eventDebugPlayerTrade;

void EventDebugPlayerTrade::EventPlayerMailSend(const EventInfoPlayerTradeMail &info)
{
    EVENTLOG("EventPlayerMailSend - id:%u recipient:%lu",
             info.player.GetGUIDLow(), info.recipient);
}

void EventDebugPlayerTrade::EventPlayerTradeAccepted(const EventInfoPlayerTradeTrade &info)
{
    EVENTLOG("EventPlayerTradeAccepted - id:%u other:%u",
             info.player.GetGUIDLow(), info.other.GetGUIDLow());
}

void EventDebugPlayerTrade::EventPlayerVendorTraded(const EventInfoPlayerTradeVendor &info)
{
    EVENTLOG("EventPlayerVendorTraded - id:%u vendor:%u item:%u count:%u",
             info.player.GetGUIDLow(), info.vendor.GetGUIDLow(), info.item.GetGUIDLow(), info.count);
}
