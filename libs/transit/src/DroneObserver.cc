#include "DroneObserver.h"

#include <string>
#include "SimulationModel.h"

DroneObserver::DroneObserver() : IObserver() {}

void DroneObserver::linkModel(SimulationModel* model) {
    this->model = model;
}

void DroneObserver::update(std::string msg) {
    model->sendNotification(msg);
}
