#ifndef VECTORMENU_H
#define VECTORMENU_H

#include "../dst/array.hpp"
#include "../utils/fileread.hpp"
#include "../utils/filewrite.hpp"

const string ARRAY_SECTION = "Array";

void vectorMenu(Array<string> arguments) {
    string command = arguments.get(0);

    if (command == "MPUSH") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        Array<string> array = readArray(name);
        array.pushBack(element);
        save(ARRAY_SECTION, name, name + " " + join(array, ','));
    } else if (command == "MLEN") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);

        Array<string> array = readArray(name);
        cout << array.size() << endl;
    } else if (command == "MSET") {
        if (arguments.size() != 4) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        } catch (invalid_argument& e) {
            throw runtime_error("argument should be number");
        }
        string value = arguments.get(3);

        Array<string> array = readArray(name);
        try {
            array.set(index, value);
        } catch (invalid_argument& e) {
            throw runtime_error("invalid index");
        }
        save(ARRAY_SECTION, name, name + " " + join(array, ','));
    } else if (command == "MINSERT") {
        if (arguments.size() != 4) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        } catch (invalid_argument& e) {
            throw runtime_error("argument should be number");
        }
        string value = arguments.get(3);

        Array<string> array = readArray(name);
        try {
            array.insert(index, value);
        } catch (invalid_argument& e) {
            throw runtime_error("invalid index");
        }
        save(ARRAY_SECTION, name, name + " " + join(array, ','));
    } else if (command == "MDEL") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        } catch (invalid_argument& e) {
            throw runtime_error("argument should be number");
        }

        Array<string> array = readArray(name);
        try {
            array.remove(index);
        } catch (invalid_argument& e) {
            throw runtime_error("incorrect index");
        }
        save(ARRAY_SECTION, name, name + " " + join(array, ','));
    } else if (command == "MGET") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);
        int index;
        try {
            index = stoi(arguments.get(2));
        } catch (invalid_argument& e) {
            throw runtime_error("argument should be number");
        }

        Array<string> array = readArray(name);
        cout << array.get(index) << endl;
    } else if (command == "MPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string name = arguments.get(1);

        Array<string> array = readArray(name);
        cout << array << endl;
    } else {
        throw runtime_error("unknown command");
    }
}

#endif