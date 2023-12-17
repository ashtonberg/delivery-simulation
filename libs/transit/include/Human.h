#ifndef HUMAN_H_
#define HUMAN_H_

#include "IEntity.h"
#include "IStrategy.h"
/**
*@brief Class to define the humans that walk around the simulation
**/
class Human : public IEntity {
 public:
  /**
   * @brief Humans are created with a name
   * @param obj JSON object containing the human's information
   */
  Human(JsonObject& obj);
  /**
  *@brief Default deconstructor for Human entities
  **/
  ~Human();
  /**
  *@brief Updates the status of the entity
  *@param dt double of how much time has passed
  **/
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
