#include "IntersectionMediator.h"
#include "CollisionDecorator.h"

IntersectionMediator::IntersectionMediator() {}

bool IntersectionMediator::notify(CollisionDecorator* entity, double dt) {
    if(entity->getStoppedAt() == -1) {
        for(int i = 0; i < this->intersections.size(); i++) {
            Intersection* curIntersection = this->intersections.at(i);
            if (curIntersection->getPosition().dist(entity->getPosition()) < curIntersection->getRadius()) {
                curIntersection->addEntityToQueue(entity->getId());
                entity->setStoppedAt(curIntersection->getId());
                return false;
            }
        }
        return true;
    } else {
        Intersection* curIntersection;
        for(int i = 0; i < this->intersections.size(); i++) {
            if(this->intersections.at(i)->getId() == entity->getStoppedAt()) {
                curIntersection = this->intersections.at(i);
                break;
            }
        }

        if(curIntersection->getFirst() == entity->getId()) {
            if(curIntersection->getIsClear() == true) {
                curIntersection->setClear(false);
                return false;
            } else {
                if (entity->getPosition().dist(curIntersection->getPosition()) < (curIntersection->getRadius()+5)) {
                    //std::cout << "here1" << std::endl;
                    //std::cout << total_time << std::endl;
                    if (this->total_time > 3){
                        entity->getEntity()->update(dt * 2);
                        //curCar->getEntity()->update(dt);
                        //std::cout << curCar->getEntity()->getPosition() << std::endl;
                        entity->setPosition(entity->getEntity()->getPosition());
                        entity->setDirection(entity->getEntity()->getDirection());

                        //std::cout << total_time << std::endl;
                    }
                    this->total_time += dt;
                    return false;
                } else {
                    //std::cout << "here2" << std::endl;
                    this->total_time = 0.0;
                    //entity->setinQueue(false);
                    entity->setStoppedAt(-1);
                    curIntersection->popQueue();
                    std::cout << "leaving queue" << std::endl;
                    curIntersection->setClear(true);
                    return true;
                }
            }
        }
        return false;
    }

}


void IntersectionMediator::updateIntersections(double dt) {
    for(int i = 0; i < this->intersections.size(); i++) {
        this->intersections.at(i)->updateIntersection(dt);
    }
}

void IntersectionMediator::addIntersection(Intersection* newIntersection) {
    this->intersections.push_back(newIntersection);
}
