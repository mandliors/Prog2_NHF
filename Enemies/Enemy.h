#ifndef ENEMY_H
#define ENEMY_H

#include "GameObjects/GameObject.h"
#include "Color/Color.h"

class Enemy : public GameObject
{
public:
    Enemy(World* worldPtr, double health = 100.0, double mass = 1.0, const Utils::Vec2d& position = Utils::Vec2d::Zero())
        : GameObject(worldPtr, health, mass, position, 0.05), Target(position) { }
    virtual ~Enemy() = default;

    void SetTarget(const Utils::Vec2d& target) { Target = target; }

    virtual double GetMoveForce() const = 0;
    virtual double GetSize() const = 0;
    virtual Col GetColor() const = 0;

protected:
    Utils::Vec2d Target;
};

#endif