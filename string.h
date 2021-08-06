//
// Created by 金琪 on 2021/8/5.
//

#pragma once
#include <iostream>

class String {
public:
    String();
    explicit String(int len);
    explicit String(const char *str);
    String(const String &s);

    friend std::ostream &operator<<(std::ostream &cout, String &s);
    friend std::istream &operator>>(std::istream &cin, String &s);
    String &operator=(const String &s);
    char &operator[](int index);
    bool operator==(String &s);
    bool operator!=(String &s);
    String operator+(const String &s);
    ~String();

private:
    char *str_{};
    int length_{};
};
