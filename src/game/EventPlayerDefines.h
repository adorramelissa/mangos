/*
 *  EventPlayerDefines.h
 *  MaNGOS
 *
 *  Created by cipherCOM on 03.08.10.
 *  Copyright 2010 Back2Basics. All rights reserved.
 *
 */

#ifndef __EVENTPLAYERDEFINES_H__
#define __EVENTPLAYERDEFINES_H__

class Player;

struct EventInfoPlayer : public EventInfo
{
    const Player &player;
    
    EventInfoPlayer(const Player &player_)
    : EventInfo(), player(player_) {}
};

#endif // __EVENTPLAYERDEFINES_H__
