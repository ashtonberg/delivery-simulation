#ifndef DRONE_OBSERVER_H_
#define DRONE_OBSERVER_H_

#include "IObserver.h"


/**
 * @brief class for DroneObserver to get messages from drones
 **/
class DroneObserver : public IObserver {
 public:
  /**
   * @brief A default constructor for DroneObserver
   **/
  DroneObserver();

  /**
   * @brief A destructor for DroneObserver
   **/
  ~DroneObserver() {}

    /**
   * @brief Links this observer to a simulation model,
   *  giving it access to the model's public variables
   *  and functions.
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
