#ifndef CARINTERSECTIONDECORATOR_H_
#define CARINTERSECTIONDECORATOR_H_

#include "math/vector3.h"
#include "IEntity.h"

class IntersectionMediator;

class CarIntersectionDecorator : IEntity {
    public:
      CarIntersectionDecorator();

      void update(double dt);
      bool getIsStopped();
      void setIsStopped(bool stopped);

    private:
      IEntity* decoratedCar;
      IntersectionMediator* mediator;
      bool isStopped;
};

#endif