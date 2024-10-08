#ifndef QUEUEMENU_H
#define QUEUEMENU_H

#include "../dst/queue.hpp"
#include "../utils/fileread.hpp"
#include "../utils/filewrite.hpp"

const string QUEUE_SECTION = "Queue";

void queueMenu(Array<string> arguments) {
    string command = arguments.get(0);

    if (command == "QPUSH") {
        if (arguments.size() != 3) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);
        string element = arguments.get(2);

        if (element.find(",") != string::npos) {
            throw runtime_error(", shouldn't be in pushed element");
        }

        Queue<string> queue = readQueue(nameArr);
        queue.enqueue(element);
        save(QUEUE_SECTION, nameArr, nameArr + " " + queue.data().join(','));
    } else if (command == "QPOP") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        Queue<string> queue = readQueue(nameArr);
        cout << "Popped: " << queue.dequeue() << endl;
        save(QUEUE_SECTION, nameArr, nameArr + " " + queue.data().join(','));
    } else if (command == "QPRINT") {
        if (arguments.size() != 2) {
            throw runtime_error("incorrect count of arguments");
        }
        string nameArr = arguments.get(1);

        Queue<string> queue = readQueue(nameArr);
        cout << queue << endl;
    } else {
        throw runtime_error("unknown command");
    }
}

#endif