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

int CollisionDecorator::getStoppedAt() {
    return this->stoppedAt;
}

void CollisionDecorator::setStoppedAt(int intersectionId) {
    this->stoppedAt = intersectionId;
}

void CollisionDecorator::setinQueue(bool isInQueue) {
    this->inQueue = isInQueue;
}

void CollisionDecorator::update(double dt) {
    if (this->collision == false) {
        //notify() return tells the decorator whether it should move or not
        if(this->intMediator->notify(this, dt)) {
            this->entity->update(dt);
            this->position = this->entity->getPosition();
            this->direction = this->entity->getDirection();
        }
        
    }
}