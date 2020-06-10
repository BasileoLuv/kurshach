#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>

class MyString
{
public:
    static const int maxSize = 20;
    char* word;
    int size;
    MyString();
    void clear();
    void clear(char* buff, int size);
    MyString(const char* source);
    MyString(const MyString& source);
    ~MyString();
    void copy(const MyString& source);
    void copy(const char* source);
    MyString& operator=(const MyString& source);
    char& operator[] (const int index);
    bool equal(MyString* str);
    bool equal(const char* source);

    MyString* split(int& size, const char delimiter);


};