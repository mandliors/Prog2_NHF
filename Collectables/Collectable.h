#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include "GameObjects/GameObject.h"

class Collectable : public GameObject
{
public:
    Collectable(World* worldPtr, const Utils::Vec2d& position = Utils::Vec2d::Zero())
        : GameObject(worldPtr, 0.0, 0.0, position, 0.0), Collected(false) { }
    virtual ~Collectable() = default;

    virtual double GetSize() const = 0;
    bool IsCollected() const { return Collected; }
    void SetCollected(bool collected) { Collected = collected; }

protected:
    bool Collected; 
};


#endif