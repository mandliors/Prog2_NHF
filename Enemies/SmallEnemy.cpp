#include "SmallEnemy.h"
#include "AssetManager/AssetManager.h"

const double SmallEnemy::Size = 50.0;
const double SmallEnemy::MoveForce = 1500.0;
const Col SmallEnemy::Color = Col(120, 60, 160);

void SmallEnemy::Update(double dt)
{
    LookAt(Target);
    AddForce(Utils::Vec2d{ cos(Rotation * DEG2RAD), sin(Rotation * DEG2RAD) } * MoveForce);
    GameObject::Update(dt);
}
void SmallEnemy::Draw() const
{
    // draw enemy
    Texture2D& texture = *AssetManager::GetTexture(AssetManager::TextureType::SMALL_ENEMY);
    DrawRectanglePro({ (float)Position.GetX() + 10.0f, (float)Position.GetY() + 10.0f, (float)Size, (float)Size }, { (float)Size * 0.5f, (float)Size * 0.5f }, (float)Rotation, { 0, 0, 0, 210});
    DrawTexturePro(texture, { 0.0f, 0.0f, (float)texture.width, (float)texture.height }, { (float)Position.GetX(), (float)Position.GetY(), (float)Size, (float)Size }, { (float)Size * 0.5f, (float)Size * 0.5f }, (float)Rotation, { 255, 255, 255, 255 }); 
    //DrawRectanglePro({ (float)Position.GetX(), (float)Position.GetY(), (float)Size, (float)Size }, { (float)Size * 0.5f, (float)Size * 0.5f }, (float)Rotation, Color);

    // draw health bar
    if (Health < MaxHealth)
        DrawHealthBar(Position - Utils::Vec2d(0.0, Size * 0.5 + 20.0), Utils::Vec2d(60.0, 5.0));
}