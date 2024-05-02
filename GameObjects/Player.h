#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "ParticleSystem/ParticleSystem.h"

class Player : public GameObject
{
public:
    Player(World* worldPtr, const Utils::Vec2d& position = Utils::Vec2d::Zero())
        : GameObject(worldPtr, 100.0, 1.0, position, 0.05), CoinCount(0), Fume() { }
    ~Player() = default;

    void Update(double dt) override;
    void Draw() const override;

    void AddCoin(int count = 1) { CoinCount += count; }
    int GetCoinCount() const { return CoinCount; }

private:
    void Shoot() const;

private:
    static const double MoveForce;
    static const Col Color;
    static const double BulletSpeed;

private:
    int CoinCount;
    ParticleSystem Fume;
};



#endif