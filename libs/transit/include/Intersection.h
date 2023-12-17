#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "IEntity.h"

#include "math/vector3.h"
#include <vector>
#include <queue>

class CollisionDecorator;
/**
  *@brief Class to define the intersections that cows/cars and drones will stop at and get in queue
  **/
class Intersection : public IEntity{
 public:
    /**
    *@brief Constructor for Intersection entities
    *@param position Vector3 of the intersection position
    *@param radius double for how big its collision radius is
    *@param entity JsonObject& for its data
    **/
    Intersection(Vector3 position, double radius, JsonObject& entity);
    /**
    *@brief Updates the status of the entity
    *@param dt double of how much time has passed
    **/
    void update(double dt);
    /**
    *@brief Gets the posiiton of the stopsign
    *@return Vector3 of its position
    **/
    Vector3 getPosition();
    /**
    *@brief Adds an entity to the stopsign queue
    *@param entity CollisionDecorator* of the entity to enter the queue
    **/
    void addEntityToQueue(CollisionDecorator* entity);
    /**
    *@brief Gets the radius of the stopsign collision area
    *@return double of the radius size
    **/
    double getRadius();
    /**
    *@brief Checks whether the stopsign queue is empty
    *@return bool whether the stopsign queue is empty
    **/
    bool getIsClear();
    /**
    *@brief Updates the status of whether or not the queue is empty
    *@param clear bool of whether or not it should be empty
    **/
    void setClear(bool clear);
    /**
    *@brief Gets the car that is next in queue
    *@return CollisionDecorator* of the car/cow/entity next in queue
    **/
    CollisionDecorator* getCar();

 private:
    Vector3 position;
    bool isClear;
    double radius;
    std::queue<CollisionDecorator*> queue;
    double total_time = 0.0;
    CollisionDecorator* curCar = nullptr;
};

#endif
