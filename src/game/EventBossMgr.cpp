/*
 *  EventBossMgr.cpp
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#include "EventBossMgr.h"
#include "Policies/SingletonImp.h"

INSTANTIATE_SINGLETON_1(EventSystemMgr<EventListenerBoss>);
EventDebugBoss eventDebugBoss;
