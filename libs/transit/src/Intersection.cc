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
        //std::cout << "IF" << std::endl;
        this->isClear = false;
        CollisionDecorator* topEntity = this->queue.front();
        this->curCar = topEntity;
        //std::cout << this->radius << std::endl;
    } else if (this->isClear == false) {
        //std::cout << "ELSE" << std::endl;
        if (curCar->getPosition().dist(this->position) < (this->radius+5)) {
            //std::cout << "here1" << std::endl;
            //std::cout << total_time << std::endl;
            if (total_time > 3){
                curCar->getEntity()->update(dt * 2);
                //curCar->getEntity()->update(dt);
                //std::cout << curCar->getEntity()->getPosition() << std::endl;
                curCar->setPosition(curCar->getEntity()->getPosition());
                curCar->setDirection(curCar->getEntity()->getDirection());

                //std::cout << total_time << std::endl;
            }
            total_time += dt;
        }else {
            //std::cout << "here2" << std::endl;
            total_time = 0.0;
            curCar->setinQueue(false);
            this->queue.pop();
            std::cout << "leaving queue" << std::endl;
            this->isClear = true;
        }

    }
}
