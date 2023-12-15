#ifndef SUBJECT_H_
#define SUBJECT_H_

#include "IObserver.h"
#include <string>
#include <vector>

/**
 * @brief Object to give to classes that need to send notifications
 **/
class Subject {
 public:
  /**
   * @brief A constructor for Subject
   **/
  Subject();

  /**
   * @brief A destructor for Subject
   **/
  ~Subject();

  /**
   * @brief Function to add an observer to the subject's list
   * 
   * @param newObserver pointer to observer to add
   **/
  void Attach(IObserver* newObserver);

  /**
   * @brief Function to remove an observer from the subject's list, pops
   *  the most recently added observer.
   **/
  void Dettach();

  /**
   * @brief Function to remove an observer from the subject's list
   * 
   * @param oldObserver pointer to observer to remove
   **/
  void CreateMessage(std::string message);

  std::vector<IObserver*> observers;

 private:
  /**
   * @brief Function to send this->message to observers
   **/
  void Send();

  std::string* message = nullptr;
  

};

#endif
