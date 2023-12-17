#ifndef COLLISION_MEDIATOR_H_
#define COLLISION_MEDIATOR_H_

#include "IEntity.h"
#include "CollisionDecorator.h"

class CollisionDecorator;
/**
*@brief Class that defines the mediator for car + drone collisions
**/
class CollisionMediator {
 public:
    /**
    *@brief Checks for collision
    **/
    void CollisionCheck();
    /**
    *@brief Adds the collision decorator
    *@param decorator the simulation's CollisionDecorator*
    **/
    void addDecorator(CollisionDecorator* decorator);
    /**
    *@brief Updates the status of the mediator
    *@param dt double of how much time has passed
    **/
    void update(double dt);
    /**
    *@brief Collision Mediator destructor
    **/
    virtual ~CollisionMediator();
 private:
    std::vector<CollisionDecorator*> decorators;
};

#endif
