#include "CollisionMediator.h"
#include "CollisionDecorator.h"

void CollisionMediator::CollisionCheck() {
    IEntity* entity1;
    IEntity* entity2;
    
    //std::cout << "OUTSIDE" << std::endl;
    for (int i = 0; i < this->decorators.size(); i++) {
        //std::cout << "INSIDE" << std::endl;
        //std::cout << entities.size() << std::endl;
        entity1 = this->decorators.at(i)->getEntity();
        //std::cout << entity1. << std::endl;
        for (int j = 0; j < this->decorators.size(); j++) {
            if ( i != j) {
                entity2 = this->decorators.at(j)->getEntity();
                //std::cout << entity1->getDirection() << std::endl;
                //std::cout << entity2->getDirection() << std::endl;
                if (entity1->getDirection() * entity2->getDirection() > 0){
                    if ( entity1->getPosition().dist(entity2->getPosition()) < 13.0) {
                        //std::cout << entity1->getPosition() << std::endl;
                        //std::cout << entity2->getPosition() << std::endl;
                        if((entity2->getPosition() - entity1->getPosition()) * entity1->getDirection() > 0) {
                            this->decorators.at(i)->colTrue();
                            //std::cout << "POOP" << std::endl;
                            break;
                        } else {
                            this->decorators.at(i)->colFalse();
                        }
                    } else {
                        this->decorators.at(i)->colFalse();
                    } 
                } else {
                    this->decorators.at(i)->colFalse();
                }
            } 
        }
    }
}


void CollisionMediator::update(double dt) {
    for(CollisionDecorator* decorator : this->decorators) {
        decorator->update(dt);
    }
}

void CollisionMediator::addDecorator(CollisionDecorator* decorator) {
    this->decorators.push_back(decorator);
}

CollisionMediator::~CollisionMediator() {
    for (int i = 0; i < this->decorators.size(); i++) {
        delete this->decorators[i];
    }

}