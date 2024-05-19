#ifndef BULLET_H
#define BULLET_H

#include "GameObjects/GameObject.h"
#include "Utils/Vec2.h"

class Bullet : public GameObject
{
public:
    /**
     * @brief Enum class for bullet target type (the bullet only damages the target type)
     */
    enum class BulletTarget { PLAYER = 0, ENEMY };

public:
    /**
     * @brief Constructs a new Bullet object
     * 
     * @param worldPtr The world that owns the object
     * @param position The position of the object
     * @param velocity The velocity of the object
     * @param target The target type of the object
     */
    Bullet(World* worldPtr, const Utils::Vec2d& position, const Utils::Vec2d& velocity, BulletTarget target)
        : GameObject(worldPtr, 0.0, 0.5, position, 0.0), Target(target) { Velocity = velocity; }
    /**
     * @brief Destroy the Bullet object (virtual needed for inheritance)
     */
    virtual ~Bullet() = default;

    /**
     * @brief Updates the bullet object
     * 
     * @param dt The delta time
     */
    virtual void Update(double dt) override;
    //virtual void Draw() const override; // this is a pure virtual function in GameObject

    /**
     * @brief Returns the target type of the bullet
     * 
     * @return BulletTarget The target type of the bullet
     */
    BulletTarget GetTarget() const { return Target; }
    /**
     * @brief Returns the size of the bullet
     * 
     * @return double The size of the bullet
     */
    virtual double GetSize() const = 0;

protected:
    BulletTarget Target;
};

#endif