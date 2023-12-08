#include "DeliveryObserver.h"

#include <string>


DeliveryObserver::DeliveryObserver(SimulationModel* sim) : IObserver(sim){
    
}

void DeliveryObserver::initSimModel(SimulationModel* sim){
    simModel = sim;
}

void DeliveryObserver::update(std::string msg){
    simModel->sendNotification("Delivery: " + msg);
}