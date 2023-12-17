#ifndef IOBSERVER_H_
#define IOBSERVER_H_

#include <string>

class SimulationModel;

/**
 * @brief class for IController used for transit service. Uses the Model View
 **/
class IObserver {
 public:
  /**
   * @brief A constructor for IObserver
   **/
  IObserver() {}

  /**
   * @brief A destructor for IObserver
   **/
  ~IObserver() {}

  /**
   * @brief Links this observer to a simulation model,
   *  giving it access to the model's public variables
   *  and functions.
   * @param model The simulation model to link.
   */
  virtual void linkModel(SimulationModel* model) = 0;

  /**
   * @brief Function to send message to simulation model
   * 
   * @param msg String containing message to be sent
   **/
  virtual void update(std::string msg) = 0;

 protected:
  SimulationModel* model = nullptr;
};

#endif
