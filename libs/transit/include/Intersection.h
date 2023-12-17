#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "IEntity.h"
#include "math/vector3.h"
#include <vector>
#include <queue>

class Intersection : public IEntity{
    public:
      Intersection(Vector3 position, double radius, JsonObject& entity);
      bool updateIntersection(int entityId);     
      Vector3 getPosition();
      void addEntityToQueue(int entityId);
      double getRadius();
      bool getIsClear();
      void setClear(bool clear); 
      void popQueue();
      int getFirst();
      void update(double dt);

    private:
      Vector3 position;
      bool isClear;
      double radius;
      std::queue<int> queue;
};

#endif