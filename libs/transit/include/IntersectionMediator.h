#ifndef INTERSECTIONMEDIATOR_H_
#define INTERSECTIONMEDIATOR_H_

#include "math/vector3.h"
#include <vector>
#include "Intersection.h"
#include "IEntity.h"

class CollisionDecorator;
/**
*@brief Mediator class to handle stop sign intersections and their queues
**/
class IntersectionMediator {
 public:
    /**
    *@brief Default constructor for intersection mediators
    **/
    IntersectionMediator();
    /**
    *@brief notifies an entity of its new status
    *@param entity CollisionDecorator* of the entity to notify
    **/
    void notify(CollisionDecorator* entity);
    /**
    *@brief Updates the status of the entity
    *@param dt double of how much time has passed
    **/
    void updateIntersections(double dt);
    /**
    *@brief Adds a new intersection to the mediator
    *@param newIntersection Intersection* to be added
    **/
    void addIntersection(Intersection* newIntersection);

 private:
    std::vector<Intersection*> intersections;
};

#endif
