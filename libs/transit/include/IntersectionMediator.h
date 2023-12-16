#ifndef INTERSECTIONMEDIATOR_H_
#define INTERSECTIONMEDIATOR_H_

#include "math/vector3.h"
#include <vector>
#include "Intersection.h"

class CarIntersectionDecorator;

class IntersectionMediator {
    public:
      IntersectionMediator();

      void notify(CarIntersectionDecorator*);

      void updateIntersections(double dt);

    private:
      std::vector<Intersection*> intersections;
};

#endif