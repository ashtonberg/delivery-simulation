#include "Intersection.h"
#include "CollisionDecorator.h"

Intersection::Intersection(Vector3 position, double radius,
JsonObject& entity) : IEntity(entity) {
    this->position = position;
    this->radius = radius;
    this->isClear = true;
}

bool Intersection::getIsClear() {
    return this->isClear;
}

void Intersection::setClear(bool clear) {
    this->isClear = clear;
}

Vector3 Intersection::getPosition() {
    return this->position;
}

double Intersection::getRadius() {
    return this->radius;
}

void Intersection::addEntityToQueue(CollisionDecorator* entity) {
    this->queue.push(entity);
    entity->setinQueue(true);
}

CollisionDecorator* Intersection::getCar() {
    return this->curCar;
}

void Intersection::update(double dt) {
    if (this->isClear && !this->queue.empty()) {
        this->isClear = false;
        CollisionDecorator* topEntity = this->queue.front();
        this->curCar = topEntity;
    } else if (this->isClear == false) {
        if (curCar->getPosition().dist(this->position) < (this->radius+5)) {
            if (total_time > 1.5) {
                curCar->getEntity()->update(dt * 2);
                curCar->setPosition(curCar->getEntity()->getPosition());
                curCar->setDirection(curCar->getEntity()->getDirection());
            }
            total_time += dt;
        } else {
            total_time = 0.0;
            curCar->setinQueue(false);
            this->queue.pop();
            this->isClear = true;
        }
    }
}
