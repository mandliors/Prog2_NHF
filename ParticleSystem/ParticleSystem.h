#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "Utils/Vec2.h"
#include "Color/Color.h"

#include <vector>

class ParticleSystem
{
public:
    ParticleSystem();
    ~ParticleSystem() = default;

    void Emit(const Utils::Vec2d& position, const Utils::Vec2d& direction, double randomAngle, double lifetime, const Col& startColor, const Col& endColor, double startSize, double endSize, int count);
    
    void Update(double dt);
    void Draw() const;

private:
    struct Particle
    {
        Particle(const Utils::Vec2d& position, const Utils::Vec2d& velocity, double lifetime, const Col& startColor, const Col& endColor, double startSize, double endSize);

        void Update(double dt);
        void Draw() const;
    
    public:
        Utils::Vec2d Position;
        Utils::Vec2d Velocity;
        double Age;
        
        double Lifetime;
        Col StartColor, EndColor;
        double StartSize, EndSize;
    };

private:
    std::vector<Particle> Particles;
};

#endif