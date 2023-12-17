#ifndef COLLISION_DECORATOR_H_
#define COLLISION_DECORATOR_H_

#include "IEntity.h"
#include "IStrategy.h"


class CollisionMediator;
class IntersectionMediator;
/**
 *@brief Collision decorator class to add collisions to entities
 */
class CollisionDecorator : public IEntity{
 public:
    /**
    *@brief Constructor for CollisionDecorator class
    *@param entity an IEntity pointer to add decorator to, a json object, and collision+intersection mediators
    *@param obj a JSON object
    *@param colMediator the simulation's collision mediator
    *@param intMediator the simulation's intersection mediator
    **/
    CollisionDecorator(IEntity* entity, JsonObject& obj,
    CollisionMediator* colMediator, IntersectionMediator* intMediator);

    // ~CollisionDecorator();
    /**
    *@brief sets collision to false
    **/
    void colFalse();
    /**
    *@brief sets collision to true
    **/
    void colTrue();
    /**
    *@brief sets isInQueue to the correct status
    *@param isInQueue boolean whether or not it is in queue
    **/
    void setinQueue(bool isInQueue);


    /**
    *@brief gets this entity
    *@return returns an IEntity*
    **/
    IEntity* getEntity();

    /**
    *@brief Updates the status of the entity
    *@param dt double of how much time has passed
    **/
    void update(double dt);

 private:
    IEntity* entity = nullptr;
    CollisionMediator* colMediator = nullptr;
    bool collision = false;
    bool inQueue = false;
    IntersectionMediator* intMediator = nullptr;
};

#endif
