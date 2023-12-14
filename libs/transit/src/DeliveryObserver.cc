#include "DeliveryObserver.h"

#include <string>


void DeliveryObserver::update(std::string msg){
    controller.sendMessageToNotification("Delivery: " + msg);
}