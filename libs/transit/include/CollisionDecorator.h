#ifndef COLLISION_DECORATOR_H_
#define COLLISION_DECORATOR_H_

#include "IEntity.h"
#include "IStrategy.h"


class CollisionMediator;
class IntersectionMediator;

class CollisionDecorator : public IEntity{
  public:
    CollisionDecorator(IEntity* entity, JsonObject& obj,
    CollisionMediator* colMediator, IntersectionMediator* intMediator);

    //~CollisionDecorator();

    void colFalse();

    void colTrue();

    void setinQueue(bool isInQueue);

    

    IEntity* getEntity();


    void update(double dt);

  private:
    IEntity* entity = nullptr;
    CollisionMediator* colMediator = nullptr;
    bool collision = false;
    bool inQueue = false;
    IntersectionMediator* intMediator = nullptr;
};

#endif