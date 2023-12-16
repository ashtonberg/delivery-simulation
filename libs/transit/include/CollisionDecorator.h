#ifndef COLLISION_DECORATOR_H_
#define COLLISION_DECORATOR_H_

#include "IEntity.h"
#include "IStrategy.h"

class CollisionMediator;

class CollisionDecorator : public IEntity{
  public:
    CollisionDecorator(IEntity* entity, JsonObject& obj, CollisionMediator* colMediator);

    //~CollisionDecorator();

    void colFalse();

    void colTrue();

    IEntity* getEntity();


    void update(double dt);

  private:
    IEntity* entity = nullptr;
    CollisionMediator* colMediator = nullptr;
    bool collision = false;
};

#endif
