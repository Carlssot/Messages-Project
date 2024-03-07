/*
 * This Object Message contains a integer for the ID of the person and a char pointer
 * for the name.
*/


#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstring>

using namespace std;

class Message {
  private:
    int ID;
    char *name;
  
  public:
    ~Message();
    Message & operator=(const Message &otherMessage);
    Message(const Message &otherMessage);
    const char *getRecipient () const;
    Message(int, char *);
    const int getID();
};

#endif
