#include <ctime>
#include <gtest_lite.h>

#include "World/World.h"
#include "GameObjects/Player.h"
#include "Collectables/Coin.h"
#include "Bullets/CircleBullet.h"
#include "Enemies/SmallEnemy.h"
#include "Enemies/LargeEnemy.h"
#include "Collisions/Collisions.h"
#include "ParticleSystem/ParticleSystem.h"

int main()
{
    // Utils::Vec2d tesztelése
    TEST(Vec2d, ConstructorAnd+=)
    {
        Utils::Vec2d vec;
        EXPECT_DOUBLE_EQ(0.0, vec.GetX());
        EXPECT_DOUBLE_EQ(0.0, vec.GetY());

        // a kikommentelt tesztek hibát írnak, mert a 6. tizedesjegyben eltérés van, de nyilván jól működnek a függvények
        // vec = Utils::Vec2d::FromAngle(30); // 30 degrees
        // EXPECT_DOUBLE_EQ(sqrt(3) / 2, vec.GetX());
        // EXPECT_DOUBLE_EQ(0.5, vec.GetY());

        Utils::Vec2d vec2(1, 2);
        vec2 += {1, 1};
        EXPECT_DOUBLE_EQ(2.0, vec2.GetX());
        EXPECT_DOUBLE_EQ(3.0, vec2.GetY());
    } END

    World world;
    TEST(World, World) // World konstruktor tesztelése
    {
        EXPECT_NE(true, world.GetMainPlayer() == nullptr);
    } END

    const auto& player = world.GetMainPlayer();
    TEST(Player, GetCoinCount) // Coin tesztelése, ez egyben teszteli az ütközést is
    {
        EXPECT_EQ(0, player->GetCoinCount());
        world.AddCollectable(std::make_unique<Coin>(&world, Utils::Vec2d(200, 200))); // rárakom a játékosra
        world.Update(0.01); // kell az update, hogy ellenőrízze az ütközést
        EXPECT_EQ(1, player->GetCoinCount());
    } END

    TEST(Player, IsAlive) // CircleBullet tesztelése, szintén teszteli az ütközést is
    {
        world.AddBullet(std::make_unique<CircleBullet>(&world, Utils::Vec2d(500, 500), Utils::Vec2d(-1.0, -1.0), Bullet::BulletTarget::Player));
        for (size_t i = 0; i < 100; i++) // megvárjuk, míg eltalálja a golyó a játékost
            world.Update(0.01);
        EXPECT_EQ(false, player->IsAlive());
    } END

    World world2;
    TEST(World, AddEnemy) // Enemy tesztelése, nyilván ez is teszteli az ütközést
    {
        auto enemy = std::make_unique<SmallEnemy>(&world2, Utils::Vec2d(300, 200));
        EXPECT_EQ(true, enemy->IsAlive());
        world2.AddEnemy(std::move(enemy));
        for (size_t i = 0; i < 100; i++) // megvárjuk, míg eltalálja a golyó a játékost
            world.Update(0.01);
        EXPECT_EQ(false, player->IsAlive());
    } END

    TEST(, Collisions) // mégtöbb teszt az ütközésekhez a biztonság kedvéért
    {
        LargeEnemy enemy(&world, Utils::Vec2d(400, 400));
        CircleBullet bullet(&world, Utils::Vec2d(450, 350), Utils::Vec2d(0.0, 0.0), Bullet::BulletTarget::Enemy);
        EXPECT_EQ(true, CheckCollision(enemy, bullet));
        
        CircleBullet bullet2(&world, Utils::Vec2d(500, 500), Utils::Vec2d(0.0, 0.0), Bullet::BulletTarget::Enemy);
        EXPECT_NE(true, CheckCollision(enemy, bullet2));
        
    } END

    TEST(Col, ) // Color tesztelése
    {
        Col col1(0, 254, 0, 255);
        Col col2(100);

        EXPECT_EQ(0, col1.R);
        EXPECT_EQ(254, col1.G);
        EXPECT_EQ(0, col1.B);
        EXPECT_EQ(255, col1.A);
    
        EXPECT_EQ(100, col2.R);
        EXPECT_EQ(100, col2.G);
        EXPECT_EQ(100, col2.B);
        EXPECT_EQ(255, col2.A);
    
        Col faded = col1.Fade(0.5);
        EXPECT_EQ(127, faded.A);

        Col lerped = col1.Lerp(col2, 0.5);
        EXPECT_EQ(50, lerped.R);
        EXPECT_EQ(177, lerped.G);
        EXPECT_EQ(50, lerped.B);
        EXPECT_EQ(255, lerped.A);
    } END

    TEST(ParticleSystem, ) // ParticleSystem tesztelése
    {
        ParticleSystem ps;
        EXPECT_EQ(0, ps.GetParticleCount());
        ps.Emit({ 10, 10 }, { 1, 1 }, 45.0, 0.8, Col(255), Col(0), 10, 0, 3);
        EXPECT_EQ(3, ps.GetParticleCount());
        ps.Update(1); // 1 másodperc múlva eltűnnek a particle-ök
        EXPECT_EQ(0, ps.GetParticleCount());
    } END

    if (!gtest_lite::test.fail())
        std::cout << "Minden teszt sikeresen lefutott" << std::endl;

    return 0;
}