#include "Coin.h"

const double Coin::Radius = 10.0;
const double Coin::SwingSpeed = 8.0;
const double Coin::SwingAmount = 5.0;

void Coin::Draw() const
{
    double offset = sin(Time * SwingSpeed) * SwingAmount;
    DrawEllipse((int)Position.GetX(), (int)(Position.GetY() + 30), 18, 8, Color{ 0, 0, 0, 210 });
    
    double width = fmaxf(2.0, (float)abs(sin(Time * SwingSpeed / 2.0) * 10.0));
    DrawEllipse((int)Position.GetX(), (int)(Position.GetY() + offset), (float)width, 10.0f, YELLOW);
    //DrawCircle((int)Position.GetX(), (int)(Position.GetY() + offset), Radius, YELLOW);
}