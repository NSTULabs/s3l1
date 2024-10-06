#ifndef DLIST_MENU
#define DLIST_MENU
#include "../dst/dlist.hpp"
#include "../utils/fileread.hpp"
#include "../utils/filewrite.hpp"

const string DLIST_SECTION = "List";

void dlistMenu(Array<string> arguments) {
    string command = arguments.get(0);

    if (command == "LPUSH") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        Dlist<string> dlist = readDlist(nameArr);
        dlist.pushBack(element);
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } else if (command == "LPUSHF") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        Dlist<string> dlist = readDlist(nameArr);
        dlist.pushForward(element);
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } else if (command == "LDELV") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string value = arguments.get(2);

        Dlist<string> dlist = readDlist(nameArr);
        dlist.removeValue(value);
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } else if (command == "LDELF") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        Dlist<string> dlist = readDlist(nameArr);
        dlist.removeForward();
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } else if (command == "LDEL") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        Dlist<string> dlist = readDlist(nameArr);
        dlist.removeBack();
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } else if (command == "LGET") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        } catch (invalid_argument& e) {
            throw runtime_error("argument should be number");
        }

        Dlist<string> dlist = readDlist(nameArr);
        cout << dlist.get(index) << endl;
    } else if (command == "LPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        Dlist<string> dlist = readDlist(nameArr);
        cout << dlist << endl;
    } else {
        throw runtime_error("unknown command");
    }
}

#endif