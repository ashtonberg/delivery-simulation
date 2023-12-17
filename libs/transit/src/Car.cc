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

void Car::update(double dt) {
    if (movement && !movement->isCompleted()) {
        movement->move(this, dt);
    } else {
        if (movement) delete movement;
        Vector3 dest;
        dest.x = ((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400;
        dest.y = position.y;
        dest.z = ((static_cast<double>(rand())) / RAND_MAX) * (1600) - 800;

        if (model) {
            movement = new AstarStrategy(position, dest, model->getGraph());
        }
    }
}
