#ifndef COIN_H
#define COIN_H

#include "Collectable.h"

class Coin : public Collectable
{
public:
    /**
     * @brief Constructs a new Coin object
     * 
     * @param worldPtr The world that owns the object
     * @param position The position of the object
     */
    Coin(World* worldPtr, const Utils::Vec2d& position) : Collectable(worldPtr, position), Time(0.0) { }

    /**
     * @brief Updates the coin object
     * 
     * @param dt The delta time
     */
    void Update(double dt) override { Time += dt; }
    /**
     * @brief Draws the coin object
     */
    void Draw() const override;

    /**
     * @brief Returns the size of the coin
     * 
     * @return double The size of the coin
     */
    double GetSize() const override { return Radius * 2.0f; }

private:
    static const double Radius;
    static const double SwingSpeed;
    static const double SwingAmount;
    
private:
    double Time; // keep track of time for the swing animation
};

#endif