/*Open the data file and reding data
 * Determine what time of command to execute per line of data
 */

#include "messageList.h"
#include <cstring>
#include <fstream>

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
  file.ignore();
  // file.getline(action, STRMAX, ' ');
  // cout << action << endl;

  while (!file.eof()) {
    if (strcmp("All", action) == 0) {
      list.listAll();

      // cout << action << " "  << ID << endl;
    } else if (strcmp("Delete", action) == 0) {
      file >> ID;
      file.ignore();
      
      //test input:
      // cout << action << " "  << ID << endl;

      list.deleteMessage(ID);
    } else if (strcmp("List", action) == 0) {
      file.getline(name, STRMAX);
      // file.ignore(5,'\n');

      // cout << action << " " << name << " " << ID << endl;
      list.listRecipient(name);
    } else if (strcmp("Receive", action) == 0) {
      file >> ID;
      file.getline(name, STRMAX);
      // file.ignore(5,'\n');

      cout << action << " " << name << " " << ID << endl;
      list.addMessage(ID, name);

      // cout << action << " " << name << " " << ID << endl;
    }

    file >> action;
    // file.getline(action, STRMAX,' ');
    // cout << action << "2" << endl;
  }

  file.close();

  return 0;
}
