#ifndef MAPMENU_H
#define MAPMENU_H

#include "../dst/map.hpp"
#include "../utils/fileread.hpp"
#include "../utils/filewrite.hpp"

const string MAP_SECTION = "Map";

void mapMenu(Array<string> arguments) {
    string command = arguments.get(0);

    if (command == "HPUSH") {
        if (arguments.size() != 4) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        string key = arguments.get(2);
        string value = arguments.get(3);

        if (key.find(",") != string::npos || value.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed key or value");
        } else if (key.find(",") != string::npos || value.find(",") != string::npos) {
            throw runtime_error("; shouldn't be in pushed key or value");
        }

        Map<string> map = readMap(name);
        map.put(key, value);
        save(MAP_SECTION, name, name + " " + map.join());
    } else if (command == "HDEL") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        string key = arguments.get(2);

        Map<string> map = readMap(name);
        map.remove(key);
        save(MAP_SECTION, name, name + " " + map.join());
    } else if (command == "HGET") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        string key = arguments.get(2);

        Map<string> map = readMap(name);
        cout << map.get(key) << endl;
        save(MAP_SECTION, name, name + " " + map.join());
    } else if (command == "HPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);

        Map<string> map = readMap(name);
        cout << map << endl;
    } else {
        throw runtime_error("unknown command");
    }
}

#endif