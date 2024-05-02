#include "LargeEnemy.h"
#include "AssetManager/AssetManager.h"

const double LargeEnemy::Size = 100.0;
const double LargeEnemy::MoveForce = 1000.0;
const Col LargeEnemy::Color = Col(255, 0, 0);

void LargeEnemy::Update(double dt)
{
    LookAt(Target);
    AddForce(Utils::Vec2d{ cos(Rotation * DEG2RAD), sin(Rotation * DEG2RAD) } * MoveForce);
    GameObject::Update(dt);
}
void LargeEnemy::Draw() const
{
    // draw enemy
    Texture2D& texture = *AssetManager::GetTexture(AssetManager::TextureType::LARGE_ENEMY);
    DrawRectanglePro({ (float)Position.GetX() + 10.0f, (float)Position.GetY() + 10.0f, (float)Size, (float)Size }, { (float)Size * 0.5f, (float)Size * 0.5f }, (float)Rotation, { 0, 0, 0, 210 });
    DrawTexturePro(texture, { 0.0f, 0.0f, (float)texture.width, (float)texture.height }, { (float)Position.GetX(), (float)Position.GetY(), (float)Size, (float)Size }, { (float)Size * 0.5f, (float)Size * 0.5f }, (float)Rotation, { 255, 255, 255, 255 }); 
    //DrawRectanglePro({ (float)Position.GetX(), (float)Position.GetY(), (float)Size, (float)Size }, { (float)Size * 0.5f, (float)Size * 0.5f }, (float)Rotation, Color);

    // draw health bar
    if (Health < MaxHealth)
        DrawHealthBar(Position - Utils::Vec2d(0.0, Size * 0.5 + 25.0), Utils::Vec2d(120.0, 10.0));
}