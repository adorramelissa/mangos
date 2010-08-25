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

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerTrade>);
EventDebugPlayerTrade eventDebugPlayerTrade;

void EventDebugPlayerTrade::EventPlayerMailSend(const EventInfoPlayerTrade &info)
{
    EVENTLOG("EventPlayerMailSend - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerTrade::EventPlayerTradeAccepted(const EventInfoPlayerTrade &info)
{
    EVENTLOG("EventPlayerTradeAccepted - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerTrade::EventPlayerTradeSpecialAccepted(const EventInfoPlayerTrade &info)
{
    EVENTLOG("EventPlayerTradeSpecialAccepted - id:%u", info.player.GetGUIDLow());
}

void EventDebugPlayerTrade::EventPlayerMerchantTraded(const EventInfoPlayerTrade &info)
{
    EVENTLOG("EventPlayerMerchantTraded - id:%u", info.player.GetGUIDLow());
}
