#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <vector>

class UT {

public:
    static std::vector<std::string> split(std::string &s, char c) {
        std::vector<std::string> ret;
        std::string tmp;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                ret.push_back(tmp);
                tmp.clear();
                continue;
            }
            tmp.push_back(s[i]);
        }
        if (!tmp.empty())
            ret.push_back(tmp);
        return ret;
    }
};

#endif