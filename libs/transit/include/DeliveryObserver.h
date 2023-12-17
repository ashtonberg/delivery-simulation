#ifndef DELIVERY_OBSERVER_H_
#define DELIVERY_OBSERVER_H_

#include "IObserver.h"


/**
 * @brief class for DeliveryObserver to get messages from packages
 **/
class DeliveryObserver : public IObserver {
 public:
  /**
   * @brief A default constructor for DeliveryObserver
   **/
  DeliveryObserver();

  /**
   * @brief A destructor for DeliveryObserver
   **/
  ~DeliveryObserver() {}

    /**
   * @brief Links this observer to a simulation model,
   *  giving it access to the model's public variables
   *  and functions.
   * 
   * @param model The simulation model to link.
   */
  void linkModel(SimulationModel* model);

  /**
   * @brief Function to send message to simulation model
   * 
   * @param msg String containing message to be sent
   **/
  void update(std::string msg);
};

#endif
