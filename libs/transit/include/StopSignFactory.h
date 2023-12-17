#ifndef STOPSIGN_FACTORY_H_
#define STOPSIGN_FACTORY_H_

#include <vector>
#include "IEntityFactory.h"
#include "StopSign.h"

/**
 *@brief Stop Sign Factory to produce Stop Sign class.
 **/
class StopSignFactory : public IEntityFactory {
  public:
    /**
     * @brief Destructor for StopSignFactory class.
     **/
    

    /**
     * @brief Creates entity using the given JSON object, if possible.
     * @param entity - JsonObject to be used to create the new entity.
     * @return Entity that was created if it was created successfully, or a
     *nullpointer if creation failed.
    **/
    IEntity* CreateEntity(JsonObject& entity);
};

#endif
