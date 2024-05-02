#include "ParticleSystem.h"

#include <raylib.h>
#include <algorithm>

static double Lerp(double a, double b, double t);

ParticleSystem::ParticleSystem() : Particles() {}

void ParticleSystem::Emit(const Utils::Vec2d& position, const Utils::Vec2d& direction, double randomAngle, double lifetime, const Col& startColor, const Col& endColor, double startSize, double endSize, int count)
{
    for (int i = 0; i < count; i++)
    {
        double angle = direction.GetAngle() + GetRandomValue((int)-randomAngle, (int)randomAngle);
        double speed = GetRandomValue(100, 200);
        Utils::Vec2d velocity = Utils::Vec2d::FromAngle(angle) * speed;
        Particles.emplace_back(position, velocity, lifetime, startColor, endColor, startSize, endSize);
    }
}

void ParticleSystem::Update(double dt)
{
    for (auto& particle : Particles)
        particle.Update(dt);

    Particles.erase(std::remove_if(Particles.begin(), Particles.end(), [](const Particle& particle) { 
            return particle.Age >= particle.Lifetime;
    }), Particles.end());
}
void ParticleSystem::Draw() const
{
    for (const auto& particle : Particles)
        particle.Draw();
}


ParticleSystem::Particle::Particle(const Utils::Vec2d& position, const Utils::Vec2d& velocity, double lifetime, const Col& startColor, const Col& endColor, double startSize, double endSize)
    : Position(position), Velocity(velocity), Age(0.0), Lifetime(lifetime), StartColor(startColor), EndColor(endColor), StartSize(startSize), EndSize(endSize) {}

void ParticleSystem::Particle::Update(double dt)
{
    Position += Velocity * dt;
    Age += dt;
}
void ParticleSystem::Particle::Draw() const
{
    double t = Age / Lifetime;
    Col color = StartColor.Lerp(EndColor, t);
    double size = Lerp(StartSize, EndSize, t);
    DrawRectanglePro({ (float)Position.GetX(), (float)Position.GetY(), (float)size, (float)size }, { 0.0f, 0.0f }, 0, color);
}

static double Lerp(double a, double b, double t)
{
    return a + (b - a) * t;
}