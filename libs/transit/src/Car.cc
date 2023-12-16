#include "Car.h"
#include <stdlib.h>
#include "AstarStrategy.h"
#include "SimulationModel.h"

#include <cmath>
#include <limits>

Car::Car(JsonObject& obj) : IEntity(obj) {}

Car::~Car() {
  if (movement) delete movement;
}

// Vector3 Car::getDestination() {
//     return this->destination;
// }

// void Car::setDestination() {
//     this->destination.x = rand() % 2900 - 1400;
//     this->destination.y = rand() % 360 + 240;
//     this->destination.z = rand() % 1600 - 800;
// }




void Car::update(double dt) {
    if (movement && !movement->isCompleted()) {
        movement->move(this, dt);
        //std::cout << this->position << std::endl;
    } else {
        //std::cout << "MOVING ELSE" << std::endl;
        if (movement) delete movement;
        Vector3 dest;
        // dest.x = ((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400;
        // dest.y = position.y;
        // dest.z = ((static_cast<double>(rand())) / RAND_MAX) * (1600) - 800;
        dest.x = 686;
        dest.y = 0;
        dest.z = 200.6;
        
        if(this->getName() == "bosscow") {
            dest.x = 469;
            dest.y = 270;
            dest.z = -100.3;
        }

        //std::cout << "before model" << std::endl;
        if (model) {
            //std::cout << "Setting movement" << std::endl;
            movement = new AstarStrategy(position, dest, model->getGraph());
            //std::cout << movement << std::endl;
        }
            
    }
}
