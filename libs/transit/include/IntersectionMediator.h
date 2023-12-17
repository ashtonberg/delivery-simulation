#ifndef INTERSECTIONMEDIATOR_H_
#define INTERSECTIONMEDIATOR_H_

#include "math/vector3.h"
#include <vector>
#include "Intersection.h"
#include "IEntity.h"

class CollisionDecorator;

class IntersectionMediator {
    public:
      IntersectionMediator();

      bool notify(CollisionDecorator* entity, double dt);

      void updateIntersections(double dt);

      void addIntersection(Intersection* newIntersection);

    private:
      std::vector<Intersection*> intersections;
      double total_time = 0.0;
};

#endif