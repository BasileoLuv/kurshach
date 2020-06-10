#pragma once
#include <string>
#include <iostream>
#include "Node.h"
#include <iomanip>
using namespace std;

struct List {
    Node* head;
    Node* tail;
    int size;
    void Insert(Node* NewNode);
    void Remove(Node* NewNode);
    void print();
    Node* findByFirstWord(const char* source);
    Node* findBySecondWord(const char* source);
    Node* findByFirstWord(MyString* word);
    Node* findBySecondWord(MyString* word);

    List() { head = tail = NULL; size = 0; };
    ~List();
    void delALL();
};

