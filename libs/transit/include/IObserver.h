#ifndef IOBSERVER_H_
#define IOBSERVER_H_

//--------------------  Observer Interface ----------------------------

/**
 * @brief class for IController used for transit service. Uses the Model View
 **/
class IObserver {
 public:
  /**
   * @brief A constructor for IObserver
   **/
  IObserver(SimulationModel* sim);

  /**
   * @brief A destructor for IObserver
   **/
  virtual ~IObserver() {}

  /**
   * @brief Function to send message to simulation model
   * @param msg String containing message to be sent
   **/
  virtual void update(std::string msg) = 0;

protected:
  SimulationModel* simModel;

};

#endif
