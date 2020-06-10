#include "MyString.h"

MyString::MyString()
{
    size = 0;
    word = new char[1];
    word[0] = '\0';
    clear();


}

void MyString::clear()
{

    for (int i = 0; i < size; i++) {
        word[i] = '\0';
    }

}
void MyString::clear(char* buff,int size)
{

    for (int i = 0; i < size; i++) {
        buff[i] = '\0';
    }

}
MyString::MyString(const char* source)
{
    size = strlen(source);
    word = new char[size + 1];
    strcpy(word, source);
}

MyString::MyString(const MyString& source)
{
    copy(source); // use the copy method
}


MyString::~MyString()
{
    size = 0;
    if (word != nullptr)
        delete[] word;
}

void MyString::copy(const MyString& source)
{
    size = source.size;
    word = new char[size + 1];
    clear();
    strcpy(word, source.word);
}
void MyString::copy(const char* source)
{
    size = strlen(source)+1;
    word = new char[size + 1];
    clear();
    strcpy(word, source);
}

MyString& MyString::operator=(const MyString& x) {
    size = x.size;
    delete[] word;
    word = new char[size];
    for (int i = 0; i < size; i++) {
        word[i] = x.word[i];
    }
    // actually not needed since x.content should already be null-terminated
    // content[length - 1] = '\0';
    return *this;
}

char& MyString::operator[](const int index)
{
    return word[index];
}

bool MyString::equal(MyString* str)
{
    return this->equal(str->word);
}

bool MyString::equal(const char* source)
{
    if (strcmp(source, word) == 0)
        return true;
    return false;
}


MyString* MyString::split(int& _size, const char delimiter)
{
    _size = 0;
    for (int i = 0; i < size; i++) {
        if (word[i] == delimiter) {
            _size++;
        }
    }
    _size++;
    char* buff = new char[this->size+1];
    clear(buff,this->size+1);
    MyString* arrStr = new MyString[_size];
    int j = 0;
    int k = 0;
    for (int i = 0; i < this->size+1; i++) {
        if (word[i] == delimiter || word[i]=='\0'){
            arrStr[j].copy(buff);
            j++;
            k = 0;
            clear(buff, this->size+1);
            continue;
        }
        buff[k] = word[i];
        k++;
    }
    return arrStr;
}
