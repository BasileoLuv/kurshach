#pragma once
#include "MyString.h"
class Node
{
public:
    MyString* FirstWord;
    MyString* SecondWord;

    Node(MyString* FirstWord2, MyString* SecondWord2);
    Node(const char* FirstWord, const char* SecondWord);
    Node(const char* FirstWord);
    ~Node() {};
    void print();

    Node* next;

};
