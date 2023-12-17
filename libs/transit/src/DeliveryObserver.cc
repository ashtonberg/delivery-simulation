#include "DeliveryObserver.h"

#include <string>
#include "SimulationModel.h"

DeliveryObserver::DeliveryObserver() : IObserver() {}

void DeliveryObserver::linkModel(SimulationModel* model) {
    this->model = model;
}

void DeliveryObserver::update(std::string msg) {
    model->sendNotification(msg);
}
