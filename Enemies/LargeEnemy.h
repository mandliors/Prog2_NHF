#ifndef LARGE_ENEMY_H
#define LARGE_ENEMY_H

#include "Enemy.h"

class LargeEnemy : public Enemy
{
public:
    LargeEnemy(World* worldPtr, const Utils::Vec2d& position = Utils::Vec2d::Zero()) : Enemy(worldPtr, 50.0, 1.0, position) { }

    void Update(double dt) override;
    void Draw() const override;

    double GetSize() const override { return Size; }
    double GetMoveForce() const override { return MoveForce; }
    Col GetColor() const override { return Color; }

private:
    static const double MoveForce;
    static const double Size;
    static const Col Color;
};

#endif