#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>

#include "GameObjects/Player.h"
#include "Collectables/Collectable.h"
#include "Enemies/Enemy.h"
#include "Bullets/Bullet.h"

class World
{
public:
    /**
     * @brief Constructs a new World object
     */
    World();

    /**
     * @brief Adds a collectable to the world (takes ownership)
     * 
     * @param collectable The collectable to add
     */
    void AddCollectable(std::unique_ptr<Collectable> collectable) { Collectables.push_back(std::move(collectable)); }
    /**
     * @brief Adds an enemy to the world (takes ownership)
     * 
     * @param enemy The enemy to add
     */
    void AddEnemy(std::unique_ptr<Enemy> enemy) { Enemies.push_back(std::move(enemy)); }
    /**
     * @brief Adds a bullet to the world (takes ownership)
     * 
     * @param bullet The bullet to add
     */
    void AddBullet(std::unique_ptr<Bullet> bullet) { Bullets.push_back(std::move(bullet)); }

    /**
     * @brief Generates objects, calls the Update function of all objects in the world
     * 
     * @param dt The delta time
     */
    void Update(double dt);
    /**
     * @brief Calls the Draw function of all objects in the world and shows FPS
     */
    void Draw() const;

    /**
     * @brief Returns the main player
     * 
     * @return Player* The main player (the world keeps ownership of the player object)
     */
    Player* GetMainPlayer() { return MainPlayer.get(); }

private:
    std::unique_ptr<Player> MainPlayer;
    std::vector<std::unique_ptr<Collectable>> Collectables;
    std::vector<std::unique_ptr<Enemy>> Enemies;
    std::vector<std::unique_ptr<Bullet>> Bullets;
};

#endif