#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "IEntity.h"
#include "CarIntersectionDecorator.h"
#include "math/vector3.h"
#include <vector>
#include <queue>

class Intersection {
    public:
      Intersection(Vector3 position, double radius);
      void updateIntersection(double dt);
      bool getIsClear();
      void setClear(bool clear);      
      Vector3 getPosition();
      void addCarToQueue(CarIntersectionDecorator* car);
      double getRadius();
    private:
      Vector3 position;
      bool isClear;
      double radius;
      std::queue<CarIntersectionDecorator*> queue;
};

#endif