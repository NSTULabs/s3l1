#include <iostream>

#include "utils/filecreate.hpp"

#include "dst/array.hpp"
#include "dst/string.hpp"

#include "menu/array.hpp"
#include "menu/avl.hpp"
#include "menu/slist.hpp"
#include "menu/dlist.hpp"
#include "menu/stack.hpp"
#include "menu/queue.hpp"
#include "menu/map.hpp"
#include "menu/set.hpp"

using namespace std;

int main() {
    string str;

    createFile(FILENAME);

    while (true) {
        cout << ">> ";
        getline(cin, str);

        Array<string> splitedStr = split(str, ' ');
        string command = splitedStr.get(0);
        if (command.substr(0, 3) == "SET") {
            try {
                setMenu(splitedStr);
            } catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } else if (command.substr(0, 2) == "DL") {
            try {
                dlistMenu(splitedStr);
            } catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } else if (command[0] == 'L') {
            try {
                listMenu(splitedStr);
            } catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } else if (command[0] == 'M') {
            try {
                vectorMenu(splitedStr);
            } catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } else if (command[0] == 'Q') {
            try {
                queueMenu(splitedStr);
            } catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } else if (command[0] == 'S') {
            try {
                stackMenu(splitedStr);
            } catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } else if (command[0] == 'H') {
            try {
                mapMenu(splitedStr);
            } catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } else if (command[0] == 'T') {
            try {
                avlTreeMenu(splitedStr);
            } catch (runtime_error& e) {
                cerr << e.what() << endl;
            }
        } else {
            cerr << "Unknown command" << endl;
        }
    }

    return 0;
}
