#ifndef OBSERVER_H_
#define OBSERVER_H_

#include "SimulationModel.h"

//--------------------  Observer Interface ----------------------------

/**
 * @brief class for IController used for transit service. Uses the Model View
 **/
class IObserver {
 public:
  /**
   * @brief A destructor for IObserver
   **/
  virtual ~IObserver() {}

  /**
   * @brief Function to send message to simulation model
   * @param msg String containing message to be sent
   **/
  virtual void update(const std::string& msg) = 0;

protected:
  SimulationModel& simModel;

};

#endif
