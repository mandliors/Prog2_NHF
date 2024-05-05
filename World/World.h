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
    World();

    void AddCollectable(std::unique_ptr<Collectable> collectable) { Collectables.push_back(std::move(collectable)); }
    void AddEnemy(std::unique_ptr<Enemy> enemy) { Enemies.push_back(std::move(enemy)); }
    void AddBullet(std::unique_ptr<Bullet> bullet) { Bullets.push_back(std::move(bullet)); }

    void Update(double dt);
    void Draw() const;

    Player* GetMainPlayer() { return MainPlayer.get(); }

private:
    std::unique_ptr<Player> MainPlayer;
    std::vector<std::unique_ptr<Collectable>> Collectables;
    std::vector<std::unique_ptr<Enemy>> Enemies;
    std::vector<std::unique_ptr<Bullet>> Bullets;
};

#endif