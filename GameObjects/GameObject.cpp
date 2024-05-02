#include "GameObject.h"
#include "World/World.h"

#include <raymath.h>

void GameObject::LookAt(const Utils::Vec2d& target)
{
    Utils::Vec2d direction = target - Position;
    Rotation = atan2(direction.GetY(), direction.GetX()) * RAD2DEG;   
}

void GameObject::Update(double dt)
{
    Acceleration = Force / Mass;
    Velocity += Acceleration * dt;
    Velocity *= (1.0 - Friction);
    Position += Velocity * dt;

    Force = Utils::Vec2d::Zero();
}

void GameObject::DrawHealthBar(const Utils::Vec2d& position, const Utils::Vec2d& size) const
{
    Utils::Vec2d HealthBarOffset = { -size.GetX() * 0.5, -size.GetY() * 0.5 };
    DrawRectangleLines((int)position.GetX() + (int)HealthBarOffset.GetX(), (int)(position.GetY() + HealthBarOffset.GetY()), (int)size.GetX(), (int)size.GetY(), BLACK);
    double healthRatio = Health / MaxHealth;
    Color color = healthRatio > 0.5 ? GREEN : healthRatio > 0.2 ? YELLOW : RED;
    DrawRectangle((int)position.GetX() + (int)HealthBarOffset.GetX(), (int)(position.GetY() + HealthBarOffset.GetY()), (int)(size.GetX() * healthRatio), (int)size.GetY(), color);
}