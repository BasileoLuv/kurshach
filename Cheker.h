#pragma once

#include <iostream>
#include "MyString.h"
using namespace std;
//���� int
int inputint()
{
    int x;
    cout << "\t Enter: >> ";
    std::cin >> x;
    while (std::cin.fail() || std::cin.get() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
        std::cout << "\t|  ��������� ���� :  ";
        std::cout << "\t| >> 1 ";

        std::cin >> x;
    }
    return x;
}

//���� ������
MyString* InputString() {
    MyString* str1 = new MyString();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    char* buff = new char[300];
    cout << "\t Enter: >> ";
    cin.getline(buff, 300);
    str1->copy(buff);
    delete[] buff;

    return str1;
}