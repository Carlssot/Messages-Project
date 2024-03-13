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

  cout  << "** All Messages **" << endl;

  while (curr != nullptr) {
    cout << "Message " << curr->message->getID() << " ";
    cout << curr->message->getRecipient() << endl;

    curr = curr->next;
  }

  cout << "**********************" << endl;
}

void messageList::listRecipient(const char *name) const {
  Node *curr = head;

  while (curr != nullptr) {
    if (strcmp(name, curr->message->getRecipient()) == 0) {
      cout << "Messages for " << curr->message->getRecipient() << ":" << endl;
      cout << "  " << curr->message->getID() << endl;
    }

    curr = curr->next;
  }
}

void messageList::deleteMessage(int ID) {
  bool deleted = false;
  Node *curr = head;

  if (head == nullptr) {
    deleted = true;
    tail = nullptr;
  } else if (head->message->getID() == ID) {
    curr = head;
    head = head->next;

    delete curr->message;
    delete curr;
    deleted = true;
  }

  while (!deleted) {
    Node *prev = nullptr;

    if (curr->message->getID() == ID) {
      prev->next = curr->next;

      if (curr == tail) {
        tail = prev;
      }

      delete curr->message;
      delete curr;
      deleted = true;
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
}
