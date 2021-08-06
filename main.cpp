#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "string.h"

std::vector<std::string> splitStr(std::string str, char delim) {
    std::stringstream ss;
    //ss.str(str);
    ss << str;
    std::vector<std::string> result;
    std::string item;
    while (getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

int main() {
//    String s1, s2;
//    std::cin >> s1 >> s2;
//    std::cout << s1 << " " << s2 << std::endl;

    std::string s("test  double space");
    auto v = splitStr(s, ' ');
    for (auto s : v)
        std::cout << s.size() << " \n";
    return 0;
}
