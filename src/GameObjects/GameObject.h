#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Utils/Vec2.h"

class World; // forward declaration
class GameObject
{
public:
    /**
     * @brief Construct a new GameObject
     * 
     * @param worldPtr The world that owns the object
     * @param health Max health of the object
     * @param mass Mass of the object
     * @param position Position of the object
     * @param friction Friction of the object
     */
    GameObject(World* worldPtr, double health = 0.0, double mass = 0.0, const Utils::Vec2d& position = Utils::Vec2d::Zero(), double friction = 0.00)
        : WorldPtr(worldPtr), MaxHealth(health), Health(health), Alive(true), Mass(mass), Position(position), Rotation(0.0), Force(Utils::Vec2d::Zero()), Acceleration(Utils::Vec2d::Zero()), Velocity(Utils::Vec2d::Zero()), Friction(friction) { }
    /**
     * @brief Destroy the Game Object object (virtual needed for inheritance)
     */
    virtual ~GameObject() = default;

    /**
     * @brief Returns the position of the object
     * 
     * @return Utils::Vec2d The position of the object
     */
    Utils::Vec2d GetPosition() const { return Position; }
    /**
     * @brief Returns the rotation of the object
     * 
     * @return double The rotation of the object
     */
    double GetRotation() const { return Rotation; }

    /**
     * @brief Returns whether the object is alive
     * 
     * @return bool Whether the object is alive
     */
    bool IsAlive() const { return Alive; }
    /**
     * @brief Deals damage to the object (decreses health, destroys if health is <= 0)
     * 
     * @param damage The amount of damage to deal
     */
    void TakeDamage(double damage) { Health -= damage; if (Health <= 0.0) Destroy(); }
    /**
     * @brief Destroys the object
     */
    void Destroy() { Alive = false; }

    /**
     * @brief Adds force to the object
     * 
     * @param force The force to add
     */
    void AddForce(const Utils::Vec2d& force) { Force += force; }
    /**
     * @brief Rotates the object to look at a target
     * 
     * @param target The target to look at
     */
    void LookAt(const Utils::Vec2d& target);

    /**
     * @brief Updates the object (using euler integration)
     * 
     * @param dt The delta time
     */
    virtual void Update(double dt);
    /**
     * @brief Draws the object
     */
    virtual void Draw() const = 0;

protected:
    void DrawHealthBar(const Utils::Vec2d& position, const Utils::Vec2d& size) const;

protected:
    World* WorldPtr;
    double MaxHealth;
    double Health;
    bool Alive;
    
    double Mass;
    Utils::Vec2d Position;
    double Rotation;

    Utils::Vec2d Force;
    Utils::Vec2d Acceleration;
    Utils::Vec2d Velocity;
    
    double Friction; // slows down the object (0.0 - 1.0)
};

#endif