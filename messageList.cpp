/*
 * Implementation for the linked list of messages methods
 */

#include "messageList.h"
#include "message.h"
#include <iomanip>
#include <iostream>

using namespace std;

messageList::messageList() {
  head = nullptr;
  tail = nullptr;
}

void messageList::addMessage(int ID, char *name) {
  Node *newNode = new Node;

  newNode->next = nullptr;
  newNode->message = new Message(ID, name);

  if (!head) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void messageList::listAll() const {
  Node *curr = head;

  cout << setw(10) << setfill('*') << " All Messages ";
  cout << setw(10) << setfill('*');

  while (curr != nullptr) {
    cout << "Message " << curr->message->getID() << " ";
    cout << curr->message->getRecipient() << endl;

    curr = curr->next;
  }

  cout << setw(30) << setfill('*') << endl;
}

void messageList::listRecipient(const char *name) const {
  Node *curr = head;

  while (curr != nullptr) {
    if (strcmp(name, curr->message->getRecipient()) == 0) {
      cout << "Messages for " << curr->message->getRecipient() << ":" << endl;
      cout << " " << curr->message->getID();
    }

    curr = curr->next;
  }
}

void messageList::deleteMessage(int ID) { bool deleted; }
