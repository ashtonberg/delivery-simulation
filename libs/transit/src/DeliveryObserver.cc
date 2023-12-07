#include "DeliveryObserver.h"

#include <string>


DeliveryObserver::DeliveryObserver(SimulationModel& sim) : IObserver(sim){
    
}

void DeliveryObserver::update(std::string msg){
    this->simModel.sendNotification("Delivery: " + msg);
}