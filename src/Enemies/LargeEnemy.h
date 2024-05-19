#ifndef LARGE_ENEMY_H
#define LARGE_ENEMY_H

#include "Enemy.h"

class LargeEnemy : public Enemy
{
public:
    /**
     * @brief Constructs a new SmallEnemy object
     * 
     * @param worldPtr The world that owns the object
     * @param position The position of the object
     */
    LargeEnemy(World* worldPtr, const Utils::Vec2d& position = Utils::Vec2d::Zero()) : Enemy(worldPtr, 50.0, 1.0, position) { }

    /**
     * @brief Updates the small enemy object
     * 
     * @param dt The delta time
     */
    void Update(double dt) override;
    /**
     * @brief Draws the small enemy object
     */
    void Draw() const override;

    /**
     * @brief Returns the size of the object
     * 
     * @return double The size of the object
     */
    double GetSize() const override { return Size; }
    /**
     * @brief Returns the move force of the object
     * 
     * @return double The move force of the object
     */
    double GetMoveForce() const override { return MoveForce; }
    /**
     * @brief Returns the color of the object
     * 
     * @return Col The color of the object
     */
    Col GetColor() const override { return Color; }
    
private:
    static const double MoveForce;
    static const double Size;
    static const Col Color;
};

#endif