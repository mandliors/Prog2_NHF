#include "Bullet.h"

#include <raylib.h>

void Bullet::Update(double dt)
{
    GameObject::Update(dt);
#ifndef CPORTA
    if (Position.GetX() < 0 || Position.GetX() > GetScreenWidth()
     || Position.GetY() < 0 || Position.GetY() > GetScreenHeight())
    {
        Destroy();
    }
#endif
}