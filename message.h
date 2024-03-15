/*
 * This Object Message contains a integer for the ID of the person and a char
 * pointer for the name.
 */

#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstring>

class Message {
private:
  int ID;
  char *name;

public:
  ~Message();
  Message(int ID, char *name);
  Message &operator=(const Message &otherMessage);
  Message(const Message &otherMessage);
  const char *getRecipient() const;
  const int getID();
};

#endif
