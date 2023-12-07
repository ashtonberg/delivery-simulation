#ifndef SUBJECT_H_
#define SUBJECT_H_

#include "IObserver.h"

/**
 * @brief Object to give to classes that need to send notifications
 **/
class Subject {
 public:
  /**
   * @brief A constructor for Subject
   **/
  Subject() {}

  /**
   * @brief A destructor for Subject
   **/
  ~Subject() {}

  /**
   * @brief Function to add an observer to the subject's list
   * 
   * @param newObserver pointer to observer to add
   **/
  void Attach(IObserver* newObserver);

  /**
   * @brief Function to remove an observer from the subject's list
   * 
   * @param oldObserver pointer to observer to remove
   **/
  void Dettach(IObserver* oldObserver);

  /**
   * @brief Function to remove an observer from the subject's list
   * 
   * @param oldObserver pointer to observer to remove
   **/
  void CreateMessage(std::string message);

 private:
  /**
   * @brief Function to send message to observers
   **/
  void Send();

};

#endif
