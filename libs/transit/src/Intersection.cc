#include "Intersection.h"

Intersection::Intersection(Vector3 position, double radius) {
    this->position = position;
    this->radius = radius;
    this->isClear = true;
    //init queue?
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

void Intersection::addCarToQueue(CarIntersectionDecorator* car) {
    this->queue.push(car);
    car->setIsStopped(true);
}

void Intersection::updateIntersection(double dt) {
    if (this->isClear && this->queue.empty() == false) {
        this->isClear = false;
        CarIntersectionDecorator* topCar = this->queue.front();
        while (topCar->getPosition().dist(this->position) < this->radius) {
            topCar->update(dt);
        }
        this->isClear = true;
        this->queue.pop();
    }
}
