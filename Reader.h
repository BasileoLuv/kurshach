
#pragma once
#include "MyString.h"
#include <iostream>
#include <string>
#include <fstream> // ���������� ����������
using namespace std;
class Reader
{
private:

public:
    void read(MyString fileName) {
        read(fileName.word);
    }
    MyString* read(const char* fileName) {
        string line;
        string output;
        ifstream myfile(fileName);
        MyString* str;
        if (myfile.is_open())
        {
            cout << "\t=================================================" << endl;
            while (getline(myfile, line))
            {
                line += '\n';
                output += line;
                cout <<"\t | "<< line ;
            }
            str = new MyString(output.c_str());
            myfile.close();
            cout << "\t=================================================" << endl;
            return str;
        }

        else {
            cout << "Unable to open file";
            return NULL;
        }

    }
};