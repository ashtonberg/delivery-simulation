#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "IEntity.h"
#include "CollisionDecorator.h"
#include "math/vector3.h"
#include <vector>
#include <queue>

class Intersection : public IEntity{
    public:
      Intersection(Vector3 position, double radius);
      void updateIntersection(double dt);     
      Vector3 getPosition();
      void addEntityToQueue(CollisionDecorator* entity);
      double getRadius();
      bool getIsClear();
      void setClear(bool clear); 

    private:
      Vector3 position;
      bool isClear;
      double radius;
      std::queue<CollisionDecorator*> queue;
};

#endif