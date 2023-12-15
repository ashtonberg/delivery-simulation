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
* @brief Updates the Human's position
* 
* @param dt difference in time since last update
*/
  void update(double dt);

   /**
   * @brief gets the current destination of the helicopter
   * @return Vector3 representing the xyz coordinates of the Human's current destination
   */  
  Vector3 getDestination();

   /**
   * @brief generates a new random destination for the Human 
   */
  void setDestination();

 private:
  Vector3 destination;
  IStrategy* toDest = nullptr;
};

#endif
