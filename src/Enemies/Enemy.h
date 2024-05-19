#ifndef ENEMY_H
#define ENEMY_H

#include "GameObjects/GameObject.h"
#include "Color/Color.h"

class Enemy : public GameObject
{
public:
    /**
     * @brief Constructs a new Enemy object
     * 
     * @param worldPtr The world that owns the object
     * @param health Max health of the object
     * @param mass Mass of the object
     * @param position Position of the object
     */
    Enemy(World* worldPtr, double health = 100.0, double mass = 1.0, const Utils::Vec2d& position = Utils::Vec2d::Zero())
        : GameObject(worldPtr, health, mass, position, 0.05), Target(position) { }
    /**
     * @brief Destroys the Enemy object (virtual needed for inheritance)
     */
    virtual ~Enemy() = default;

    /**
     * @brief Sets the target of the enemy (where it will move towards)
     * 
     * @param target The target to set
     */
    void SetTarget(const Utils::Vec2d& target) { Target = target; }

    /**
     * @brief Returns the move force of the object (needed because of inheritance)
     * 
     * @return double The move force of the object
     */
    virtual double GetMoveForce() const = 0;
    /**
     * @brief Returns the size of the object (needed because of inheritance)
     * 
     * @return double The size of the object
     */
    virtual double GetSize() const = 0;
    /**
     * @brief Returns the color of the object (needed because of inheritance)
     * 
     * @return Col The color of the object
     */
    virtual Col GetColor() const = 0;

protected:
    Utils::Vec2d Target;
};

#endif