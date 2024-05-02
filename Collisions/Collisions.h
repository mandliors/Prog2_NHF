#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "GameObjects/Player.h"
#include "Collectables/Collectable.h"
#include "Bullets/Bullet.h"
#include "Enemies/Enemy.h"

bool CheckCollision(const Player& player, const Collectable& collectable);
bool CheckCollision(const Player& player, const Bullet& bullet);
bool CheckCollision(const Player& player, const Enemy& enemy);
bool CheckCollision(const Enemy& enemy, const Bullet& bullet);

#endif