#include "CollisionDecorator.h"

CollisionDecorator::CollisionDecorator(IEntity* entity, JsonObject& obj,
CollisionMediator* colMediator) : IEntity(obj){
    this->entity = entity;
    this->colMediator = colMediator;
}

void CollisionDecorator::colFalse() {
    this->collision = false;
}

void CollisionDecorator::colTrue() {
    this->collision = true;
}

IEntity* CollisionDecorator::getEntity() {
    return this->entity;
}

void CollisionDecorator::update(double dt) {
    if (collision == false) {
        //std::cout << "update" << std::endl;
        this->entity->update(dt);
    
        this->position = this->entity->getPosition();
        this->direction = this->entity->getDirection();
    }
}