#include "CollisionDecorator.h"

CollisionDecorator::CollisionDecorator(JsonObject& obj, IEntity* entity,
    CollisionMediator* colMediator) : IEntity(obj) {
    this->entity = entity;
    this->colMediator = colMediator;
}

void CollisionDecorator::update(double dt) {
    collision = colMediator->isColliding();
    if (collision == false) {
        this->entity->update(dt);
    }
}