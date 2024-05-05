#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Utils/Vec2.h"

class World; // forward declaration
class GameObject
{
public:
    GameObject(World* worldPtr, double health = 0.0, double mass = 0.0, const Utils::Vec2d& position = Utils::Vec2d::Zero(), double friction = 0.00)
        : WorldPtr(worldPtr), MaxHealth(health), Health(health), Alive(true), Mass(mass), Position(position), Rotation(0.0), Force(Utils::Vec2d::Zero()), Acceleration(Utils::Vec2d::Zero()), Velocity(Utils::Vec2d::Zero()), Friction(friction) { }
    virtual ~GameObject() = default;

    Utils::Vec2d GetPosition() const { return Position; }
    double GetRotation() const { return Rotation; }

    bool IsAlive() const { return Alive; }
    void TakeDamage(double damage) { Health -= damage; if (Health <= 0.0) Destroy(); }
    void Destroy() { Alive = false; }

    void AddForce(const Utils::Vec2d& force) { Force += force; }
    void LookAt(const Utils::Vec2d& target);

    virtual void Update(double dt); // euler integration
    virtual void Draw() const = 0;

protected:
#ifndef CPORTA
    void DrawHealthBar(const Utils::Vec2d& position, const Utils::Vec2d& size) const;
#else
    void DrawHealthBar() const;
#endif

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