//
// Created by Kofta on 5/29/2022.
//

#include <sstream>
#include <utility>
#include "File.h"
#include "fstream"

void File::write(std::string s) {
    std :: fstream file;
    file.open(fileName, std::ios_base::app | std::ios_base::in | std::ios_base::out);
    file << s;
    file.close();
}

std::string File::get() {
    std::ifstream file(fileName);
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

void File::clear() {
    std :: ofstream file(fileName);
    file << "";
    file.close();
}

File::File(std :: string name) {
    fileName = std::move(name);
}
