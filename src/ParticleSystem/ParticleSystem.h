#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "Utils/Vec2.h"
#include "Color/Color.h"

#include <vector>

class ParticleSystem
{
public:
    /**
     * @brief Constructs a new Particle System object
     */
    ParticleSystem();
    /**
     * @brief Destroys the Particle System object
     */
    ~ParticleSystem() = default;

    /**
     * @brief Returns the number of particles in the system
     * 
     * @return size_t The number of particles in the system
     */
    size_t GetParticleCount() const { return Particles.size(); }
    /**
     * @brief Emits particles with given parameters
     * 
     * @param position The position to emit the particles from
     * @param direction The direction the particles will move
     * @param randomAngle The max angle the direction will be randomized by
     * @param lifetime The lifetime of the particles in seconds
     * @param startColor The starting color of the particles
     * @param endColor The ending color of the particles
     * @param startSize The starting size of the particles
     * @param endSize The ending size of the particles
     * @param count The number of particles to emit
     */
    void Emit(const Utils::Vec2d& position, const Utils::Vec2d& direction, double randomAngle, double lifetime, const Col& startColor, const Col& endColor, double startSize, double endSize, size_t count);
    
    /**
     * @brief Updates the particles in the system
     * 
     * @param dt The delta time
     */
    void Update(double dt);
    /**
     * @brief Draws the particles in the system
     */
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