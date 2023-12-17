#include "Intersection.h"

Intersection::Intersection(Vector3 position, double radius, JsonObject& entity) : IEntity(entity) {
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

void Intersection::popQueue() {
    this->queue.pop();
}

int Intersection::getFirst() {
    return this->queue.front();
}

void Intersection::update(double dt) {}

void Intersection::addEntityToQueue(int id) {
    this->queue.push(id);
}


bool Intersection::updateIntersection(int entityId) {
    if (this->queue.front() == entityId) {
        this->isClear = false;
        this->queue.pop();
        return true;
    } else {
        return false;
    }

}