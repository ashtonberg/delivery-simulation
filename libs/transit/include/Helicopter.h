#ifndef Helicopter_H_
#define Helicopter_H_

#include "IEntity.h"
#include "IStrategy.h"
/**
*@brief Class to define the helicopters that fly over the simulation
**/
class Helicopter : public IEntity {
 public:
  /**
   * @brief Helicopter are created with a name
   * @param obj JSON object containing the drone's information
   */
  Helicopter(JsonObject& obj);
  /**
  *@brief Default deconstructor for Helicoper objects
  **/
  ~Helicopter();
  /**
  *@brief Updates the status of the entity
  *@param dt double of how much time has passed
  **/
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
