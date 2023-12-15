#ifndef COLLISION_MEDIATOR_H_
#define COLLISION_MEDIATOR_H_

#include "IEntity.h"

class CollisionMediator {
  public:
    
    bool isColliding();
    void addEntity(IEntity* entity);
    
    virtual ~CollisionMediator();
  private:
    std::vector<IEntity*> entities;
};

#endif