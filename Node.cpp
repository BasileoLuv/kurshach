#include "Node.h"

Node::Node(MyString* FirstWord2, MyString* SecondWord2)
{
    this->FirstWord = new MyString(*FirstWord2);
    this->SecondWord = new MyString(*SecondWord2);
    //this->SecondWord = SecondWord2;
    next = NULL;
}

Node::Node(const char* FirstWord, const char* SecondWord)
{
    this->FirstWord = new MyString(FirstWord);
    this->SecondWord = new MyString(SecondWord);
    next = NULL;
}

Node::Node(const char* FirstWord)
{
    this->FirstWord = new MyString(FirstWord);
    next = NULL;
}

void Node::print()
{
    if(this && FirstWord && SecondWord)
        std::cout << FirstWord->word << "     | " << SecondWord->word << std::endl;
}