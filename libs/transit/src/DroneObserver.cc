#include "DroneObserver.h"

#include <string>


DroneObserver::DroneObserver(SimulationModel* sim) : IObserver(sim) {

}

void DroneObserver::initSimModel(SimulationModel* sim){
    simModel = sim;
}

void DroneObserver::update(std::string msg){
    simModel->sendNotification("Drone: " + msg);
}