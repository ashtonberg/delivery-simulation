#include "IntersectionMediator.h"
#include "CollisionDecorator.h"

IntersectionMediator::IntersectionMediator() {}

void IntersectionMediator::notify(CollisionDecorator* entity) {
    //std::cout << "notify" << std::endl;
    //std::cout << this->intersections.size() << std::endl;
    for(int i = 0; i < this->intersections.size(); i++) {
        //std::cout << "checking intersections" << std::endl;
        Intersection* curIntersection = this->intersections.at(i);
        if (curIntersection->getPosition().dist(entity->getPosition()) < curIntersection->getRadius()) {
            curIntersection->addEntityToQueue(entity);
            std::cout << "ADDED TO QUEUE" << std::endl;
            break;
        }
    }

}

void IntersectionMediator::updateIntersections(double dt) {
    for(int i = 0; i < this->intersections.size(); i++) {
        this->intersections.at(i)->update(dt);
    }
}

void IntersectionMediator::addIntersection(Intersection* newIntersection) {
    this->intersections.push_back(newIntersection);
}
