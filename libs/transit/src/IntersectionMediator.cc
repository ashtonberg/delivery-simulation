#include "IntersectionMediator.h"

IntersectionMediator::IntersectionMediator() {
    //init intersections ?
}

void IntersectionMediator::notify(CarIntersectionDecorator* car) {
    if (car->getIsStopped() == false) {
        for(int i = 0; i < this->intersections.size(); i++) {
            Intersection* curIntersection = this->intersections.at(i);
            if (curIntersection->getPosition().dist(car->getPosition()) < curIntersection->getRadius()) {
                curIntersection->addCarToQueue(car);
                break;
            }
        }
    }
}

void IntersectionMediator::updateIntersections(double dt) {
    for(int i = 0; i < this->intersections.size(); i++) {
        this->intersections.at(i)->updateIntersection(dt);
    }
}