#ifndef STOPSIGN_H_
#define STOPSIGN_H_

#include "IEntity.h"
/**
*@brief Class to define the stopsign that sits in the middle of intersections 
**/
class StopSign : public IEntity {
 public:
    /**
    * @brief Stop signs are created with a name
    * @param obj JSON object containing the stop sign's information
    **/
    StopSign(JsonObject& obj);
    /**
    *@brief Default deconstructor for a stop sign
    **/
    ~StopSign();
    /**
    *@brief Updates the status of the entity
    *@param dt double of how much time has passed
    **/
    void update(double dt);
};

#endif
