#ifndef STOPSIGN_H_
#define STOPSIGN_H_

#include "IEntity.h"

class StopSign : public IEntity {
  public:
  /**
   * @brief Stop signs are created with a name
   * @param obj JSON object containing the stop sign's information
   */
    StopSign(JsonObject& obj);

    ~StopSign();

    void update(double dt);
};

#endif
