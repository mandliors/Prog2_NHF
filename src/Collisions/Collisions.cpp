#include "Collisions.h"

#include <raylib.h>

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