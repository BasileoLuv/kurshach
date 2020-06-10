#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//#include <Windows.h>
#include "Cheker.h"
#include "Reader.h"
#include "List.h"
using namespace std;


List list;
Reader reader;
void translate(MyString* str) {
    if (str == nullptr) {
        cout << "������ �����" << endl;
        return;
    }
    int q = 0;
    MyString* arrStr = str->split(q, ' ');
    //cout << "\t ";
    for (int i = 0; i < q; i++) {
        if (list.findByFirstWord(&arrStr[i]) == nullptr)
            cout << arrStr[i].word << " ";
        else {
            cout << "\t " << list.findByFirstWord(&arrStr[i])->SecondWord->word << " ";
        }
    }
    cout << endl;
}
Node* find() {
    do {
        cout << "\t 1 - Find by First word " << endl;
        cout << "\t 2 - Find by Second word " << endl;
        cout << "\t Enter: >> ";
        int x = inputint();
        switch (x) {
            case 1:
                return list.findByFirstWord(InputString());
            case 2:
                return list.findBySecondWord(InputString());
            default:
                cout << "\t " << "invalid number" << endl;
                break;
        }

    } while (true);
}
void menu() {

    int x = -1;
    Node* tmp = nullptr;
    do {
        cout << "\t 1 - Add new word " << endl;
        cout << "\t 2 - Delete word " << endl;
        cout << "\t 3 - Find word " << endl;
        cout << "\t 4 - Raplace word " << endl;
        cout << "\t 5 - Print Dictionary " << endl;
        cout << "\t 6 - Translate from keyboard" << endl;
        cout << "\t 7 - Translate from File" << endl;
        x = inputint();
        MyString* second; MyString* first;
        switch (x) {
            case 1:
                cout << "\t Input First word" << endl;
                first = InputString();
                cout << "\t Input Second word" << endl;
                second = InputString();
                list.Insert(new Node(first, second));
                cout << "\t Success add!" << endl;
                break;
            case 2:
                cout << "\t ===Delete====" << endl;
                list.Remove(find());
                break;
            case 3:
                cout << "\t ===Find====" << endl;
                tmp = find();
                if (tmp == nullptr) {
                    cout << "\t Not found " << endl;
                    break;
                }
                else {
                    tmp->print();
                }
                break;
            case 4:
                cout << "\t ===Replace====" << endl;
                tmp = find();
                if (tmp == nullptr) {
                    cout << "\t Not found " << endl;
                    break;
                }
                else {
                    tmp->print();
                    cout << "\t 1 - Replace First word " << endl;
                    cout << "\t 2 - Replace Second word " << endl;
                    cout << "\t 3 - Replace First and Second words " << endl;
                    int x2 = inputint();
                    switch (x2) {
                        case 1:
                            tmp->FirstWord = InputString();
                            break;
                        case 2:
                            tmp->SecondWord = InputString();
                            break;
                        case 3:
                            tmp->FirstWord = InputString();
                            tmp->SecondWord = InputString();
                            break;
                        default:
                            cout << "\t " << "invalid number" << endl;
                            break;
                    }
                }
                break;
            case 5:
                list.print();
                break;
            case 6:
                cout << "\t Input u string" << endl;
                translate(InputString());
                break;
            case 7:
                translate(reader.read("kek.txt"));
                break;
            default:
                cout << "\t " << "invalid number" << endl;
                break;
        }

    } while (true);
}

int main()
{
    setlocale(LC_ALL, "rus");
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    list.Insert(new Node("�����", "�����"));
    list.Insert(new Node("�����", "�����"));


    cout << "\t " << "+++++++++++++++++" << endl;
    menu();

    return 0;
}