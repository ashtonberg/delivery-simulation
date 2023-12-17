#include "CollisionMediator.h"
#include "CollisionDecorator.h"

void CollisionMediator::CollisionCheck() {
    IEntity* entity1;
    IEntity* entity2;

    for (int i = 0; i < this->decorators.size(); i++) {
        entity1 = this->decorators.at(i)->getEntity();
        for (int j = 0; j < this->decorators.size(); j++) {
            if (i != j) {
                entity2 = this->decorators.at(j)->getEntity();
                if ((entity1->getDirection() -
                entity2->getDirection()).magnitude() < .3) {
                    if (entity1->getPosition().dist(entity2->getPosition()) <
                    13.0) {
                        if ((entity2->getPosition() - entity1->getPosition()) *
                        entity1->getDirection() > 0) {
                            this->decorators.at(i)->colTrue();
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
    for (CollisionDecorator* decorator : this->decorators) {
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
