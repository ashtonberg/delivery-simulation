#ifndef CAR_H_
#define CAR_H_

#include <vector>
#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

class Car;

class Car : public IEntity {
 public:
  /**
  * @brief Cars are created with a name
  * 
  * @param obj JSON object containing the car's information
  */
  Car(JsonObject& obj);
  /**
  *@brief Default deconstructor for car entities
  **/
  ~Car();

/**
* @brief Updates the Human's position
* 
* @param dt difference in time since last update
*/
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
