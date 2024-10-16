#ifndef DLIST_MENU
#define DLIST_MENU
#include "../dst/dlist.hpp"
#include "../utils/fileread.hpp"
#include "../utils/filewrite.hpp"

const string DLIST_SECTION = "DList";

void dlistMenu(Array<string> arguments) {
    string command = arguments.get(0);

    if (command == "DLPUSH") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        DList<string> dlist = readDList(nameArr);
        dlist.pushBack(element);
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } else if (command == "DLPUSHF") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        DList<string> dlist = readDList(nameArr);
        dlist.pushForward(element);
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } else if (command == "DLDELV") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string value = arguments.get(2);

        DList<string> dlist = readDList(nameArr);
        dlist.removeValue(value);
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } else if (command == "DLDELF") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        DList<string> dlist = readDList(nameArr);
        dlist.removeForward();
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } else if (command == "DLDEL") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        DList<string> dlist = readDList(nameArr);
        dlist.removeBack();
        save(DLIST_SECTION, nameArr, nameArr + " " + dlist.join(','));
    } else if (command == "DLGET") {
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

        DList<string> dlist = readDList(nameArr);
        cout << dlist.get(index) << endl;
    } else if (command == "DLPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        DList<string> dlist = readDList(nameArr);
        cout << dlist << endl;
    } else {
        throw runtime_error("unknown command");
    }
}

#endif