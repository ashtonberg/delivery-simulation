#include "Car.h"
#include <stdlib.h>
#include "AstarStrategy.h"
#include "SimulationModel.h"

#include <cmath>
#include <limits>

Car::Car(JsonObject& obj) : IEntity(obj) {
    this->setDestination();
}

Vector3 Car::getDestination() {
    return this->destination;
}

void Car::setDestination() {
    this->destination.x = rand() % 2900 - 1400;
    this->destination.y = rand() % 360 + 240;
    this->destination.z = rand() % 1600 - 800;
}




void Car::update(double dt) {
    if (!toDest) {
        toDest = new AstarStrategy(position, destination, model->getGraph());
    }
    if (toDest->isCompleted()) {
        this->setDestination();
        delete toDest;
        toDest = new AstarStrategy(position, destination, model->getGraph());
    } else {
        toDest->move(this, dt);
    }
}
