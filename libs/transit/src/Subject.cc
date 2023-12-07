#include "Subject.h"


Subject::Subject() {
}

Subject::~Subject() {
}

void Subject::Attach(IObserver* newObserver){
    this->observers.push_back(newObserver);
}

void Subject::Dettach(IObserver* oldObserver){
    this->observers.pop_back();
}

void Subject::CreateMessage(std::string message){
    this->message.clear();
    this->message = message;
}

void Subject::Send(){
    for (int i = 0; i < (this->observers.size()); ++i){
        this->observers[i]->update(this->message);
    }
}

