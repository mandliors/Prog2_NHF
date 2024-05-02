#ifndef CIRCLEBULLET_H
#define CIRCLEBULLET_H

#include "Bullet.h"
#include "Color/Color.h"

class CircleBullet : public Bullet
{
public:
    CircleBullet(World* worldPtr, const Utils::Vec2d& position, const Utils::Vec2d& direction, BulletTarget target)
        : Bullet(worldPtr, position, direction.GetNormalized() * Speed, target) { }

    // void Update(double dt) override; // no need to override
    void Draw() const override;

    double GetSize() const override { return Radius; }

private:
    static const double Radius;
    static const double Speed;
    static const Col Color;
};

#endif