// Implementation file for the Object message methods

#include "message.h"
#include <cstring>

Message::Message(int ID, char *name) {
  this->name = new char[strlen(name) + 1];

  strcpy(this->name, name);

  this->ID = ID;
}

const char *Message::getRecipient() const { return this->name; }

const int Message::getID() { return this->ID; }

Message::Message(const Message &otherMessage) {
  this->name = new char[strlen(otherMessage.name) + 1];

  strcpy(this->name, otherMessage.name);

  this->ID = otherMessage.ID;
}

Message &Message::operator=(const Message &otherMessage) {
  if (this != &otherMessage) { // chech for self assignment
    if (this->name) {
      delete[] this->name;
    }

    this->name = new char[strlen(otherMessage.name) + 1];

    strcpy(this->name, otherMessage.name);

    this->ID = otherMessage.ID;
  }

  return *this;
}

Message::~Message() { delete[] this->name; }
