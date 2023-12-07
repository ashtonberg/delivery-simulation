#ifndef DRONE_OBSERVER_H_
#define DRONE_OBSERVER_H_

#include "IObserver.h"

/**
 * @brief class for DroneObserver to get messages from drones
 **/
class DroneObserver : public IObserver{
 public:
  /**
   * @brief A constructor for DroneObserver
   **/
  DroneObserver(SimulationModel& sim);

  /**
   * @brief A destructor for DroneObserver
   **/
  virtual ~DroneObserver() {}

  /**
   * @brief Function to send message to simulation model
   * 
   * @param msg String containing message to be sent
   **/
  void update(std::string msg);

};

#endif
