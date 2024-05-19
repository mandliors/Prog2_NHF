#ifndef CIRCLEBULLET_H
#define CIRCLEBULLET_H

#include "Bullet.h"
#include "Color/Color.h"

class CircleBullet : public Bullet
{
public:
    /**
     * @brief Constructs a new CircleBullet object
     * 
     * @param worldPtr The world that owns the object
     * @param position The position of the object
     * @param direction The direction of the object
     * @param target The target type of the object
     */
    CircleBullet(World* worldPtr, const Utils::Vec2d& position, const Utils::Vec2d& direction, BulletTarget target)
        : Bullet(worldPtr, position, direction.GetNormalized() * Speed, target) { }

    // void Update(double dt) override; // no need to override
    /**
     * @brief Draws the circle bullet object
     */
    void Draw() const override;

    /**
     * @brief Returns the size of the circle bullet
     * 
     * @return double The size of the circle bullet
     */
    double GetSize() const override { return Radius; }

private:
    static const double Radius;
    static const double Speed;
    static const Col Color;
};

#endif