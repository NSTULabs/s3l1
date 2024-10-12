#ifndef FILECREATE_H
#define FILECREATE_H

#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

void createFile(const string filename) {
    if (fs::exists(filename)) {
        return;
    }

    ofstream file(filename);

    if (file.is_open()) {
        file << "Map" << endl << endl;
        file << "Array" << endl << endl;
        file << "Queue" << endl << endl;
        file << "Stack" << endl << endl;
        file << "AvlTree" << endl << endl;
        file << "DList" << endl << endl;
        file << "SList" << endl << endl;
        file << "Set" << endl << endl;
        file.close();
    } else {
        throw runtime_error("Error opening file for writing");
    }
}

#endif
