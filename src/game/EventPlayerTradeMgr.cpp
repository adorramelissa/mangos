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

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerPlayerTrade>);
EventDebugPlayerTrade eventDebugPlayerTrade;
