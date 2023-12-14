#include "DroneObserver.h"

#include <string>



void DroneObserver::update(std::string msg){
    controller.sendMessageToNotification("Drone: " + msg);
}