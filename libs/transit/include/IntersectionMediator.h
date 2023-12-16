#ifndef INTERSECTIONMEDIATOR_H_
#define INTERSECTIONMEDIATOR_H_

#include "math/vector3.h"
#include <vector>
#include "Intersection.h"
#include "IEntity.h"


class IntersectionMediator {
    public:
      IntersectionMediator();

      void notify(IEntity* entity);

      void updateIntersections(double dt);

      void addIntersection(Intersection* newIntersection);

    private:
      std::vector<Intersection*> intersections;
};

#endif