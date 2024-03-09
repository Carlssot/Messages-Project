/*
 *This object is a linked list of messages, each message in the list is a node that contains
 *A Message object and a pointer to the next message.
*/

#ifndef MESSAGELIST_H
#define MESSAGELIST_H 

#include "message.h"
#include <iostream>

class messageList {
private:
  struct Node {
    Message *message;
    Node *next;
  };

  Node *head;
  Node *tail;

  messageList & operator=(const messageList &) = delete;
  messageList(const Message &) = delete; 
  
public:
  void addMessage(int, char *);
  void listAll() const;
  void listRecipient(const char *) const;
  void deleteMessage(int);

  messageList();
  // ~messageList();
};

#endif
