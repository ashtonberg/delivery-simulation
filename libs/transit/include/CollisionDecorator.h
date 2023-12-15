#ifndef COLLISION_DECORATOR_H_
#define COLLISION_DECORATOR_H_

#include "IEntity.h"
#include "CollisionMediator.h"

class CollisionDecorator : public IEntity {
  public:
    CollisionDecorator(JsonObject& obj, IEntity* entity, CollisionMediator* colMediator);

    //~CollisionDecorator();

    // void stop();
    // void go();
    void update(double dt);

  private:
    IEntity* entity = nullptr;
    CollisionMediator* colMediator = nullptr;
    bool collision = false;
};

#endif
