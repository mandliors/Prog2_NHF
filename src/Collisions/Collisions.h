#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "GameObjects/Player.h"
#include "Collectables/Collectable.h"
#include "Bullets/Bullet.h"
#include "Enemies/Enemy.h"

/**
 * @brief Checks if the player collides with the collectable (AABB collision detection)
 * 
 * @param player The player object
 * @param collectable The collectable object
 * @return bool True if the player collides with the collectable, false otherwise 
 */
bool CheckCollision(const Player& player, const Collectable& collectable);
/**
 * @brief Checks if the player collides with the bullet (AABB collision detection)
 * 
 * @param player The player object
 * @param bullet The bullet object
 * @return bool True if the player collides with the bullet, false otherwise 
 */
bool CheckCollision(const Player& player, const Bullet& bullet);
/**
 * @brief Checks if the player collides with the enemy (AABB collision detection)
 * 
 * @param player The player object
 * @param enemy The enemy object
 * @return bool True if the player collides with the enemy, false otherwise 
 */
bool CheckCollision(const Player& player, const Enemy& enemy);
/**
 * @brief Checks if the enemy collides with the bullet (AABB collision detection)
 * 
 * @param enemy The enemy object
 * @param bullet The enemy object
 * @return bool True if the enemy collides with the bullet, false otherwise 
 */
bool CheckCollision(const Enemy& enemy, const Bullet& bullet);

#endif