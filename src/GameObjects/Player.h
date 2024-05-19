#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "ParticleSystem/ParticleSystem.h"

class Player : public GameObject
{
public:
    /**
     * @brief Constructs a new Player object
     * 
     * @param worldPtr The world that owns the object
     * @param position The position of the object
     */
    Player(World* worldPtr, const Utils::Vec2d& position = Utils::Vec2d::Zero())
        : GameObject(worldPtr, 100.0, 1.0, position, 0.05), CoinCount(0), Fume() { }
    /**
     * @brief Destroys the Player object
     */
    ~Player() = default;

    /**
     * @brief Updates the player object
     * 
     * @param dt The delta time
     */
    void Update(double dt) override;
    /**
     * @brief Draws the player object
     */
    void Draw() const override;

    /**
     * @brief Adds coins to the player
     * 
     * @param count The number of coins to add
     */
    void AddCoin(size_t count = 1) { CoinCount += count; }
    /**
     * @brief Returns the coin count of the player
     * 
     * @return size_t The coin count of the player
     */
    size_t GetCoinCount() const { return CoinCount; }

private:
    void Shoot() const;

private:
    static const double MoveForce;
    static const Col Color;
    static const double BulletSpeed;

private:
    size_t CoinCount;
    ParticleSystem Fume;
};



#endif