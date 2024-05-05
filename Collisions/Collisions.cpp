#include "Collisions.h"

#ifndef CPORTA
#include <raylib.h>
#else
typedef struct Rectangle {
    float x;                // Rectangle top-left corner position x
    float y;                // Rectangle top-left corner position y
    float width;            // Rectangle width
    float height;           // Rectangle height
} Rectangle;

bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2)
{
    if (rec1.x + rec1.width < rec2.x || rec1.x > rec2.x + rec2.width) return false;
    if (rec1.y + rec1.height < rec2.y || rec1.y > rec2.y + rec2.height) return false;
    return true;
}
#endif

bool CheckCollision(const Player& player, const Collectable& collectable)
{
    Rectangle playerAABB {
        (float)player.GetPosition().GetX() - 60.0f,
        (float)player.GetPosition().GetY() - 60.0f,
        120.0f,
        120.0f
    };
    Rectangle circleAABB {
        (float)collectable.GetPosition().GetX() - (float)collectable.GetSize(),
        (float)collectable.GetPosition().GetY() - (float)collectable.GetSize(),
        20.0f,
        20.0f
    };
    return CheckCollisionRecs(playerAABB, circleAABB);
}
bool CheckCollision(const Player& player, const Bullet& bullet)
{
    Rectangle playerAABB {
        (float)player.GetPosition().GetX() - 60.0f,
        (float)player.GetPosition().GetY() - 60.0f,
        120.0f,
        120.0f
    };
    Rectangle circleAABB {
        (float)bullet.GetPosition().GetX() - (float)bullet.GetSize() * 5.0f,
        (float)bullet.GetPosition().GetY() - (float)bullet.GetSize() * 5.0f,
        10.0f,
        10.0f
    };
    return CheckCollisionRecs(playerAABB, circleAABB);
}
bool CheckCollision(const Player& player, const Enemy& enemy)
{
    Rectangle playerAABB {
        (float)player.GetPosition().GetX() - 60.0f,
        (float)player.GetPosition().GetY() - 60.0f,
        120.0f,
        120.0f
    };
    Rectangle enemyAABB {
        (float)enemy.GetPosition().GetX() - (float)enemy.GetSize() * 0.5f,
        (float)enemy.GetPosition().GetY() - (float)enemy.GetSize() * 0.5f,
        120.0f,
        120.0f
    };
    return CheckCollisionRecs(playerAABB, enemyAABB);
}
bool CheckCollision(const Enemy& enemy, const Bullet& bullet)
{
    Rectangle enemyAABB {
        (float)enemy.GetPosition().GetX() - (float)enemy.GetSize() * 0.5f,
        (float)enemy.GetPosition().GetY() - (float)enemy.GetSize() * 0.5f,
        120.0f,
        120.0f
    };
    Rectangle circleAABB {
        (float)bullet.GetPosition().GetX() - (float)bullet.GetSize() * 0.5f,
        (float)bullet.GetPosition().GetY() - (float)bullet.GetSize() * 0.5f,
        10.0f,
        10.0f
    };
    return CheckCollisionRecs(enemyAABB, circleAABB);
}