#ifndef DRONE_OBSERVER_H_
#define DRONE_OBSERVER_H_

#include "IObserver.h"

class IObserver;

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
   * @brief A constructor for DroneObserver
   * 
   * @param sim simulation model to send messages to
   **/
  DroneObserver(SimulationModel* sim);

  /**
   * @brief A destructor for DroneObserver
   **/
  ~DroneObserver() {}

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
