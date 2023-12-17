#include "StopSignFactory.h"

IEntity* StopSignFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("stopsign") == 0) {
    std::cout << "Stop sign Created" << std::endl;
    return new StopSign(entity);
  }
  return nullptr;
}