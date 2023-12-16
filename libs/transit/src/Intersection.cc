#include "Intersection.h"

Intersection::Intersection(Vector3 position, double radius) {
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

void Intersection::updateIntersection(double dt) {
    if (this->isClear && this->queue.empty() == false) {
        this->isClear = false;
        CollisionDecorator* topEntity = this->queue.front();
        while (topEntity->getPosition().dist(this->position) < this->radius) {
            topEntity->update(dt);
        }
        this->queue.pop();
        this->isClear = true;
    }
}
