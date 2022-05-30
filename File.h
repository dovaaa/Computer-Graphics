//
// Created by Kofta on 5/29/2022.
//

#ifndef GRAPHICS_FILE_H
#define GRAPHICS_FILE_H

#include <iostream>

class File {
private:
    std :: string fileName;
public:
    File(){

    }
    void write(std::string);
    std::string get();
    void clear();
    explicit File(std :: string name);
};


#endif //GRAPHICS_FILE_H
