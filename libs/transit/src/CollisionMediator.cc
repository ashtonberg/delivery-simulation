#include "CollisionMediator.h"


bool CollisionMediator::isColliding() {
    return true;
}

void CollisionMediator::addEntity(IEntity* entity) {
    this->entities.push_back(entity);
}

CollisionMediator::~CollisionMediator() {
    for (int i = 0; i < this->entities.size(); i++) {
        delete this->entities[i];
    }

}