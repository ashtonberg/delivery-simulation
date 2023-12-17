#ifndef COLLISION_MEDIATOR_H_
#define COLLISION_MEDIATOR_H_

#include "IEntity.h"
#include "CollisionDecorator.h"

class CollisionDecorator;

class CollisionMediator {
  public:
    
    void CollisionCheck();
    void addDecorator(CollisionDecorator* decorator);
    void update(double dt);
    
    virtual ~CollisionMediator();
  private:
    std::vector<CollisionDecorator*> decorators;
};

#endif