#include "IntersectionMediator.h"
#include "CollisionDecorator.h"

IntersectionMediator::IntersectionMediator() {}

bool IntersectionMediator::notify(CollisionDecorator* entity, double dt) {
    if(entity->getStoppedAt() == -1) {  //entity not at intersection
        for(int i = 0; i < this->intersections.size(); i++) {
            Intersection* curIntersection = this->intersections.at(i);
            if (curIntersection->getPosition().dist(entity->getPosition()) < curIntersection->getRadius()) {
                curIntersection->addEntityToQueue(entity->getId());
                entity->setStoppedAt(curIntersection->getId());
                return false;
            }
        }
        return true;
    } else {    //entity is at intersection
        Intersection* curIntersection;
        //find intersection the entity is at
        for(int i = 0; i < this->intersections.size(); i++) { 
            if(this->intersections.at(i)->getId() == entity->getStoppedAt()) {
                curIntersection = this->intersections.at(i);
                break;
            }
        }
        
        if(curIntersection->getFirst() == entity->getId()) {
            //if the entity is the first one at the intersection and the intersection is clear,
            // set the intersection to not clear so because this entity will now go
            if(curIntersection->getIsClear() == true) {
                curIntersection->setClear(false);
                return false;
            } else {
                //the entity is moving through the intersection
                if (entity->getPosition().dist(curIntersection->getPosition()) < (curIntersection->getRadius()+5)) {
                    if (this->total_time > 3){
                        entity->getEntity()->update(dt * 2);
                        entity->setPosition(entity->getEntity()->getPosition());
                        entity->setDirection(entity->getEntity()->getDirection());
                    }
                    this->total_time += dt;
                    return false;
                } else {
                    //the entity made it through the intersection
                    this->total_time = 0.0;
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



void IntersectionMediator::addIntersection(Intersection* newIntersection) {
    this->intersections.push_back(newIntersection);
}
