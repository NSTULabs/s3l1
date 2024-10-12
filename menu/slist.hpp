#ifndef LIST_MENU
#define LIST_MENU
#include "../dst/slist.hpp"
#include "../utils/fileread.hpp"
#include "../utils/filewrite.hpp"

const string SLIST_SECTION = "SList";

void listMenu(Array<string> arguments) {
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

        SList<string> slist = readSList(nameArr);
        slist.pushBack(element);
        save(SLIST_SECTION, nameArr, nameArr + " " + slist.join(','));
    } else if (command == "LPUSHF") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        SList<string> slist = readSList(nameArr);
        slist.pushForward(element);
        save(SLIST_SECTION, nameArr, nameArr + " " + slist.join(','));
    } else if (command == "LDELV") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string value = arguments.get(2);

        SList<string> slist = readSList(nameArr);
        slist.removeValue(value);
        save(SLIST_SECTION, nameArr, nameArr + " " + slist.join(','));
    } else if (command == "LDELF") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        SList<string> slist = readSList(nameArr);
        slist.removeForward();
        save(SLIST_SECTION, nameArr, nameArr + " " + slist.join(','));
    } else if (command == "LDEL") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        SList<string> slist = readSList(nameArr);
        slist.removeBack();
        save(SLIST_SECTION, nameArr, nameArr + " " + slist.join(','));
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

        SList<string> slist = readSList(nameArr);
        cout << slist.get(index) << endl;
    } else if (command == "LPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        SList<string> slist = readSList(nameArr);
        cout << slist << endl;
    } else {
        throw runtime_error("unknown command");
    }
}

#endif