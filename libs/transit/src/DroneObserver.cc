#include "DroneObserver.h"

#include <string>


DroneObserver::DroneObserver(SimulationModel& sim) : IObserver(sim){

}

void DroneObserver::update(std::string msg){
    this->simModel.sendNotification("Drone: " + msg);
}