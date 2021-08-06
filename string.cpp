//
// Created by 金琪 on 2021/8/5.
//
#include <cstring>
#include "string.h"

String::String() = default;

String::String(int len) {
    this->length_ = len;
    this->str_ = new char[len];
    memset(this->str_, 0, len);
}

String::String(const char *str) {
    if (str == nullptr) {
        this->length_ = 0;
        this->str_ = new char[1];
        strcpy(this->str_, "");
        return;
    }
    this->length_ = static_cast<int>(strlen(str));
    this->str_ = new char[this->length_ + 1];
    strcpy(this->str_, str);
}

String::String(const String &s) {
    this->length_ = s.length_;
    this->str_ = new char[this->length_ + 1];
    strcpy(this->str_, s.str_);
}

std::ostream &operator<<(std::ostream &cout, String &s) {
    if (s.str_ != nullptr)
        cout << s.str_;
    return cout;
}

std::istream &operator>>(std::istream &cin, String &s) {
    if (s.str_ != nullptr) {
        delete[] s.str_;
        s.str_ = nullptr;
        s.length_ = 0;
    }
    char tmp[1024];
    cin >> tmp;
    int len = static_cast<int>(strlen(tmp));
    s.length_ = len;
    s.str_ = new char[len + 1];
    strcpy(s.str_, tmp);
    return cin;
}

String &String::operator=(const String &s) {
    if (this == &s)
        return *this;

    if (this->str_ != nullptr) {
        delete[] this->str_;
        this->str_ = nullptr;
        this->length_ = 0;
    }
    this->length_ = s.length_;
    this->str_ = new char[this->length_ + 1];
    strcpy(this->str_, s.str_);
    return *this;
}

char &String::operator[](int index) {
    return this->str_[index];
}

bool String::operator==(String &s) {
    if (this == &s)
        return true;
    if (this->length_ != s.length_)
        return false;
    if (strcmp(this->str_, s.str_) != 0)
        return false;
    return true;
}

bool String::operator!=(String &s) {
    return !(*this == s);
}

String String::operator+(const String &s) {
    int len = this->length_ + s.length_ + 1;
    String str(len);
    strcat(str.str_, this->str_);
    strcat(str.str_, s.str_);
    return str;
}

String::~String() {
    if (this->str_ != nullptr) {
        delete[] this->str_;
        this->str_ = nullptr;
        this->length_ = 0;
    }
}
