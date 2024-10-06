#ifndef FILEWRITE_H
#define FILEWRITE_H

// сохраняет в file.data. Работает для list,array,queue,stack
void save(string section, string name, string writeline) {
    ifstream file(FILENAME);

    if (!file.is_open()) {
        throw runtime_error("error opening file");
    }

    Array<string> fileLines;  // Вектор для хранения строк файла
    string line;
    bool isArraySection = false;
    bool foundArray = false;

    while (getline(file, line)) {
        if (line == section) {
            isArraySection = true;
        } else if (isArraySection && line == "") {
            isArraySection = false;
            if (!foundArray) {
                fileLines.pushBack(writeline);
            }
        }

        if (isArraySection) {
            Array<string> splittedLine = split(line, ' ');

            if (splittedLine.size() == 2 && splittedLine.get(0) == name) {
                // Нашли нужный массив, заменяем его на новый
                line = writeline;
                foundArray = true;
            }
        }

        fileLines.pushBack(line);  // Сохраняем строку
    }

    file.close();  // Закрываем файл после чтения

    // Открываем файл для записи (перезаписываем содержимое файла)
    ofstream outFile(FILENAME);
    if (!outFile.is_open()) {
        throw runtime_error("Error opening file for writing");
    }

    // Записываем все строки обратно в файл
    for (int i = 0; i < fileLines.size(); i++) {
        outFile << fileLines.get(i) << endl;
    }

    outFile.close();  // Закрываем файл после записи
}

#endif