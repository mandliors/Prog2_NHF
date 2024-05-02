#ifndef COIN_H
#define COIN_H

#include "Collectable.h"

class Coin : public Collectable
{
public:
    Coin(World* worldPtr, const Utils::Vec2d& position) : Collectable(worldPtr, position), Time(0.0) { }

    void Update(double dt) override { Time += dt; }
    void Draw() const override;

    double GetSize() const override { return Radius * 2.0f; }

private:
    static const double Radius;
    static const double SwingSpeed;
    static const double SwingAmount;
    
private:
    double Time; // keep track of time for the swing animation
};

#endif