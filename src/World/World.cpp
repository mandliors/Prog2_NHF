#include "World.h"
#include "GameObjects/Player.h"
#include "Collectables/Coin.h"
#include "Enemies/SmallEnemy.h"
#include "Enemies/LargeEnemy.h"
#include "Collisions/Collisions.h"

#include <algorithm>

static Utils::Vec2d GenerateRandomPositionForEnemy();

World::World()
{
    MainPlayer = std::make_unique<Player>(this, Utils::Vec2d(200, 200));
}

void World::Update(double dt)
{
    if (!MainPlayer->IsAlive()) return;

    // generate coins and enemies every second (but not always)
    static double timer = 0.0;
    timer += dt;
    double inverseSpeed = 1.0 + (double)MainPlayer->GetCoinCount() / 20.0;
    if (timer > 1.0 / inverseSpeed)
    {
        if (rand() % 5 == 0) AddEnemy(std::make_unique<LargeEnemy>(this, GenerateRandomPositionForEnemy()));
        else AddEnemy(std::make_unique<SmallEnemy>(this, GenerateRandomPositionForEnemy()));
        if (rand() % 4 == 0) AddCollectable(std::make_unique<Coin>(this, Utils::Vec2d(rand() % GetScreenWidth(), rand() % GetScreenHeight())));
        timer = 0.0;
    }

    // update player
    MainPlayer->Update(dt);
    MainPlayer->LookAt(Utils::Vector2ToVec2(GetMousePosition()));

    // update enemies
    for (auto& e : Enemies)
    {
        e->SetTarget(MainPlayer->GetPosition());
        e->Update(dt);
    }

    // update collectables, check collision
    for (auto& c : Collectables)
    {
        c->Update(dt);
        if (CheckCollision(*MainPlayer, *c))
        {
            c->SetCollected(true);
            MainPlayer->AddCoin();
        }
    }

    // update bullets
    for (auto& b : Bullets)
    {
        b->Update(dt);
        if (b->GetTarget() == Bullet::BulletTarget::PLAYER && CheckCollision(*MainPlayer, *b))
        {
            MainPlayer->Destroy();
            b->Destroy();
        }
        else if (b->GetTarget() == Bullet::BulletTarget::ENEMY)
        {
            for (auto& e : Enemies)
            {
                if (CheckCollision(*e, *b))
                {
                    e->TakeDamage(10);
                    b->Destroy();
                }
            }
        }
    }

    // check player-enemy collision
    for (auto& e : Enemies)
    {
        if (CheckCollision(*MainPlayer, *e))
        {
            MainPlayer->TakeDamage(34.0);
            e->Destroy();
        }
    }

    // remove dead objects
    std::erase_if(Collectables, [](const auto& c) { return c->IsCollected(); });
    std::erase_if(Bullets, [](const auto& b) { return !b->IsAlive(); });
    std::erase_if(Enemies, [](const auto& e) { return !e->IsAlive(); });
}
void World::Draw() const
{
    // draw collectables
    for (const auto& c : Collectables)
        c->Draw();

    // draw bullets
    for (const auto& b : Bullets)
        b->Draw();
    
    // draw enemies
    for (const auto& e : Enemies)
        e->Draw();

    // draw player
    MainPlayer->Draw();

    // draw stats
    char buffer[10];
    sprintf(buffer, "%ld coins", MainPlayer->GetCoinCount());
    DrawText(buffer, 10, 70, 40, YELLOW);
    sprintf(buffer, "%d fps", GetFPS());
    DrawText(buffer, GetScreenWidth() - 150, 20, 40, YELLOW);

    if (!MainPlayer->IsAlive())
        DrawText("Game Over", GetScreenWidth() / 2 - 180, GetScreenHeight() / 2 - 50, 60, RED);
}

static Utils::Vec2d GenerateRandomPositionForEnemy()
{
    // above/below or left/right of the screen
    if (rand() % 2 == 0)
    {
        // above or below
        if (rand() % 2 == 0)
            return Utils::Vec2d(rand() % GetScreenWidth(), -50);
        else
            return Utils::Vec2d(rand() % GetScreenWidth(), GetScreenHeight() + 50);
    }
    else
    {
        // left or right
        if (rand() % 2 == 0)
            return Utils::Vec2d(-50, rand() % GetScreenHeight());
        else
            return Utils::Vec2d(GetScreenWidth() + 50, rand() % GetScreenHeight());
    }
}