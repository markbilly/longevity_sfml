#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "entity.h"

class Player : public Entity {
public:
	Player();
	~Player();
};

#endif