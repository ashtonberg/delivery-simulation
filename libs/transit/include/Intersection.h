#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "IEntity.h"

#include "math/vector3.h"
#include <vector>
#include <queue>

class CollisionDecorator;

class Intersection : public IEntity{
    public:
      Intersection(Vector3 position, double radius, JsonObject& entity);
      void update(double dt);     
      Vector3 getPosition();
      void addEntityToQueue(CollisionDecorator* entity);
      double getRadius();
      bool getIsClear();
      void setClear(bool clear);
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