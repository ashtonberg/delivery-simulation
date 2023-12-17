#include "Package.h"
#include "Robot.h"
#include "SimulationModel.h"

Package::Package(JsonObject &obj) : IEntity(obj) {
  this->subject = new Subject();
}

Package::~Package() {
  if (subject) delete subject;
}

Vector3 Package::getDestination() const {
  return destination;
}

std::string Package::getStrategyName() const {
  return strategyName;
}

void Package::setStrategyName(std::string strategyName_) {
  strategyName = strategyName_;
}

void Package::update(double dt) {}

void Package::initDelivery(Robot* owner) {
  if (!subject->observers.size())
    subject->Attach(model->deliveryObs);
  this->owner = owner;
  owner->requestedDelivery = false;
  requiresDelivery = false;
  destination = owner->getPosition();
  subject->CreateMessage(
  owner->getName() +
  "'s Package: Created. ID: " + std::to_string(this->id));
}

void Package::handOff() {
  if (owner) {
    subject->CreateMessage(
    owner->getName() +
    "'s Package: Delivered! ID: " + std::to_string(this->id));
    owner->receive(this);
  }
}
