#ifndef DELIVERY_OBSERVER_H_
#define DELIVERY_OBSERVER_H_

#include "IObserver.h"

/**
 * @brief class for DeliveryObserver to get messages from deliveries
 **/
class DeliveryObserver : public IObserver{
 public:
  /**
   * @brief A constructor for DeliveryObserver
   **/
  DeliveryObserver(SimulationModel& sim);

  /**
   * @brief A destructor for DeliveryObserver
   **/
  virtual ~DeliveryObserver() {}

  /**
   * @brief Function to send message to simulation model
   * 
   * @param msg String containing message to be sent
   **/
  void update(std::string msg);



};

#endif
