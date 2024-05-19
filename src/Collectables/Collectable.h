#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include "GameObjects/GameObject.h"

class Collectable : public GameObject
{
public:
    /**
     * @brief Constructs a new Collectable object
     * 
     * @param worldPtr The world that owns the object
     * @param position The position of the object
     */
    Collectable(World* worldPtr, const Utils::Vec2d& position = Utils::Vec2d::Zero())
        : GameObject(worldPtr, 0.0, 0.0, position, 0.0), Collected(false) { }
    /**
     * @brief Destroys the Collectable object (virtual needed for inheritance)
     */
    virtual ~Collectable() = default;

    /**
     * @brief Returns the size of the object
     * 
     * @return double The size of the object
     */
    virtual double GetSize() const = 0;
    /**
     * @brief Returns whether the object is collected
     * 
     * @return bool True if the object is collected, false otherwise
     */
    bool IsCollected() const { return Collected; }
    /**
     * @brief Sets whether the object is collected
     * 
     * @param collected True if the object is collected, false otherwise
     */
    void SetCollected(bool collected) { Collected = collected; }

protected:
    bool Collected; 
};


#endif