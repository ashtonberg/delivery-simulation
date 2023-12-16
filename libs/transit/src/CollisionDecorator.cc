#include "CollisionDecorator.h"
#include "IntersectionMediator.h"

CollisionDecorator::CollisionDecorator(IEntity* entity, JsonObject& obj,
CollisionMediator* colMediator, IntersectionMediator* intMediator) : IEntity(obj){
    this->entity = entity;
    this->colMediator = colMediator;
    this->intMediator = intMediator;
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

void CollisionDecorator::setinQueue(bool isInQueue) {
    this->inQueue = isInQueue;
}

void CollisionDecorator::update(double dt) {
    if (collision == false) {
        //std::cout << "update" << std::endl;
        if (!inQueue) {
            this->intMediator->notify(this);
        
            this->entity->update(dt);
        
            this->position = this->entity->getPosition();
            //std::cout << this->position << std::endl;
            this->direction = this->entity->getDirection();
        }
        
        
    }
}