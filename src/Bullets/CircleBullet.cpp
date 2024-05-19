#include "CircleBullet.h"

const double CircleBullet::Radius = 5.0f;
const double CircleBullet::Speed = 3000.0f;
const Col CircleBullet::Color = Col(0, 255, 40);

void CircleBullet::Draw() const
{
    DrawCircle((int)Position.GetX(), (int)Position.GetY(), Radius, Color);
}