#ifndef SETMENU_H
#define SETMENU_H

#include "../dst/set.hpp"
#include "../utils/fileread.hpp"
#include "../utils/filewrite.hpp"

const string SET_SECTION = "Set";

void setMenu(Array<string> arguments) {
    string command = arguments.get(0);

    if (command == "SETADD") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        string key = arguments.get(2);

        if (key.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed key or value");
        }

        Set<bool> set = readSet(name);
        set.put(key);
        save(SET_SECTION, name, name + " " + set.join());
    } else if (command == "SETDEL") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        string key = arguments.get(2);

        Set<bool> set = readSet(name);
        set.remove(key);
        save(SET_SECTION, name, name + " " + set.join());
    } else if (command == "SET_AT") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        string key = arguments.get(2);

        Set<bool> set = readSet(name);
        cout << set.contains(key) << endl;
        save(SET_SECTION, name, name + " " + set.join());
    } else if (command == "SETPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);

        Set<bool> set = readSet(name);
        cout << set << endl;
    } else {
        throw runtime_error("unknown command");
    }
}

#endif