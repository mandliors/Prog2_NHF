#include "Player.h"
#include "Bullets/CircleBullet.h"
#include "World/World.h"

#include <raylib.h>

using namespace Utils;

const double Player::MoveForce = 6000.0;
const Col Player::Color = Col(0, 255, 255);
const double Player::BulletSpeed = 1000.0;

void Player::Update(double dt)
{
    int horizontalMovement = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    int verticalMovement = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
    double moveForce = MoveForce;
    Vec2d dir = Vec2d::FromAngle(Rotation);

    if (horizontalMovement != 0 || verticalMovement != 0)
    {
        AddForce(Vec2d(horizontalMovement * moveForce, verticalMovement * moveForce));
        Fume.Emit(Position - dir * 25, -dir, 45.0, 0.8, Col(255, 234, 97, 255), Col(255, 255, 255, 0), 10, 0, 3);
    }
    else
    {
        Fume.Emit(Position - dir * 25, -dir, 45.0, 0.8, Col(255, 234, 97, 255), Col(255, 255, 255, 0), 10, 0, 1);
    }

    //if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        Shoot();

    GameObject::Update(dt);
    Fume.Update(dt);
}
void Player::Draw() const
{
    // draw fume
    Fume.Draw();

    // draw player
    Vec2d v1 = Position + Vec2d(-30, -40).Rotate(Rotation);
    Vec2d v2 = Position + Vec2d(-30,  40).Rotate(Rotation);
    Vec2d v3 = Position + Vec2d( 70,   0).Rotate(Rotation);
    Vec2d offset = Vec2d(10, 10);

    DrawTriangle(v1 + offset, v2 + offset, v3 + offset, { 0, 0, 0, 210 });
    DrawTriangle(v1, v2, v3, Color);

    // draw health bar
    DrawHealthBar(Utils::Vec2d(90.0, 30.0), Utils::Vec2d(160.0, 40.0));
}

void Player::Shoot() const
{
    Vec2d dir = Vec2d::FromAngle(Rotation);
    Vec2d offset = dir * 60;
    WorldPtr->AddBullet(std::make_unique<CircleBullet>(WorldPtr, Position + offset, dir * BulletSpeed, Bullet::BulletTarget::ENEMY));
}