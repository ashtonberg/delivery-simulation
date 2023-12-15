#include "Subject.h"

#include <string.h>

Subject::Subject() {
    this->observers = {};
}

Subject::~Subject() {
    while ((this->observers).size()){
        this->observers.pop_back();
    }
    if (this->message)
        delete this->message;
}

void Subject::Attach(IObserver* newObserver){
    this->observers.push_back(newObserver);
}

void Subject::Dettach(){
    this->observers.pop_back();
}

void Subject::CreateMessage(std::string message){
    if(this->message)
        delete this->message;
    this->message = new std::string(message);
    this->Send();
}

void Subject::Send(){
    std::string sendMe = *this->message;
    for (int i = 0; i < (this->observers.size()); ++i){
        this->observers[i]->update(sendMe);
    }
}

