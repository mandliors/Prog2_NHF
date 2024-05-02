#ifndef BULLET_H
#define BULLET_H

#include "GameObjects/GameObject.h"
#include "Utils/Vec2.h"

class Bullet : public GameObject
{
public:
    enum class BulletTarget { Player = 0, Enemy };

public:
    Bullet(World* worldPtr, const Utils::Vec2d& position, const Utils::Vec2d& velocity, BulletTarget target)
        : GameObject(worldPtr, 0.0, 0.5, position, 0.0), Active(true), Target(target) { Velocity = velocity; }
    virtual ~Bullet() = default;

    virtual void Update(double dt) override;
    //virtual void Draw() const override; // this is a pure virtual function in GameObject

    bool IsActive() const { return Active; }
    BulletTarget GetTarget() const { return Target; }
    virtual double GetSize() const = 0;

protected:
    bool Active;
    BulletTarget Target;
};

#endif