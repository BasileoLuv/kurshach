#include "List.h"

//Ââîä äàííûõ
void List::Insert(Node* NewNode)
{
    if (head == NULL) {
        head = tail = NewNode;
        head->next = NULL;
    }
    else {
        tail->next = NewNode;
        tail = NewNode;
    }
    size++;
    tail->next = NULL;
}
//Óäàëåíèå
void List::Remove(Node* NewNode) {
    if (head) {
        if (head == NewNode) {
            head = head->next;
        }
        else {
            Node* temp = head;
            while (temp && temp->next != NewNode) {
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "Ýëåìåíò íå íàéäåí" << endl;
                return;
            }
            else
            if (temp->next == NewNode) {
                if (tail == NewNode) {
                    tail = temp;
                }
                temp->next = NewNode->next;
            }
        }
        delete NewNode;
        size--;
    }
}

//Âûâîä äàííûõ
void List::print()
{
    if (head) {
        cout << "\t### FirstWord           |   SecondWord           ###" << endl;
        Node* temp = head;
        for (; temp->next; temp = temp->next)
        {
            temp->print();
        }
        temp->print();
    }
}

Node* List::findByFirstWord(const char* source)
{
    if (head) {
        Node* temp = head;
        do {
            if (temp->FirstWord->equal(source)) {
                return temp;
            }
            temp = temp->next;
        } while (temp != NULL);
    }
    return NULL;
}
Node* List::findBySecondWord(const char* source)
{
    if (head) {
        Node* temp = head;
        do {
            if (temp->SecondWord->equal(source)) {
                return temp;
            }

            temp = temp->next;
        } while (temp != NULL);
    }
    return NULL;
}

Node* List::findByFirstWord(MyString* word){
    Node* q = findByFirstWord(word->word);
    return q;
}
Node* List::findBySecondWord(MyString* word){
    Node* q = findBySecondWord(word->word);
    return q;
}



//Äåñòðóêòîð
List::~List()
{
    //	delALL();
}

void List::delALL() {
    while (head) {
        this->Remove(head);
    }
    size = 0;
    head = NULL;
}