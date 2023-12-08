#ifndef DELIVERY_OBSERVER_H_
#define DELIVERY_OBSERVER_H_

#include "IObserver.h"

class IObserver;

/**
 * @brief class for DeliveryObserver to get messages from deliveries
 **/
class DeliveryObserver : public IObserver {
 public:
  /**
   * @brief A default constructor for DeliveryObserver
   **/
  DeliveryObserver();

  /**
   * @brief A constructor for DeliveryObserver
   * 
   * @param sim simulation model to send messages to
   **/
  DeliveryObserver(SimulationModel* sim);

  /**
   * @brief A destructor for DeliveryObserver
   **/
  ~DeliveryObserver() {}

  /**
   * @brief A way to add the simulation model after initialization
   **/
  void initSimModel(SimulationModel* sim);

  /**
   * @brief Function to send message to simulation model
   * 
   * @param msg String containing message to be sent
   **/
  void update(std::string msg);



};

#endif
