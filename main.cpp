/*Open the data file and reding data
 * Determine what time of command to execute per line of data
 */

#include "messageList.h"
#include <cstring>
#include <fstream>
#include <string>

using namespace std;
const int STRMAX = 100;

int main(int argc, char *argv[]) {

  if (argc != 2) {
    cerr << "Usage: " << argv[0] << "<filename>" << endl;
    return 1;
  }

  messageList list;

  ifstream file;
  file.open(argv[1]);

  if (!file.is_open()) {
    cout << "Error opening file." << endl;
  }

  char name[STRMAX];
  char action[STRMAX];
  int ID;

  file >> action;

  while (!file.eof()) {
    if (strcmp("All", action) == 0) {
      list.listAll();

    } else if (strcmp("Delete", action) == 0) {
      file >> ID;

      // cout << action << " " << name << " " << ID << endl;
      // list.deleteMessage(ID);
    } else if (strcmp("List", action) == 0) {
      file.getline(name, STRMAX);

      // cout << action << " " << name << " " << ID << endl;
      list.listRecipient(name);
    } else if (strcmp("Receive", action) == 0) {
      file >> ID;
      file.getline(name, STRMAX);
      list.addMessage(ID, name);

      // cout << action << " " << name << " " << ID << endl;
    }

    file >> action;
  }

  file.close();

  return 0;
}
