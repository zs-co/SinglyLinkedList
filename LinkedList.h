#include <iostream>
#include "Node.h"

class List{
public:
    Node* head;
    Node* tail;

    List(){
        head = nullptr;
        tail = nullptr;
    }
    void prepend(int);
    void append(int);
    void remove(int);
    void show();
    void removeHead();
    void removeTail();
    int get(int);
};

void List::append(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    if (this->head == nullptr){
        head = temp;
        tail = temp;
        return;
    }

    Node* node = head;
    while (node->next != nullptr){
        node = node->next;
    }
    node->next = temp;
    tail = temp->next;
    //std::cout << tail->data << std::endl;
}

void List::show(){
    Node* temp = head;
    while (temp != nullptr){
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

void List::prepend(int data) {
    Node* temp = new Node();
    Node* node = head;
    temp->data = data;
    temp->next = node;
    head = temp;
}

void List::remove(int index) {
    int i = 0;
    Node* temp = head;
    Node* prev = nullptr;
    if (head != nullptr){
        if (index == 0){
           removeHead();
            return;
        }
        while (temp->next != nullptr && index != i){
            prev = temp;
            temp = temp->next;
            ++i;
        }
        prev->next = temp->next;
        delete temp;

    }
}

void List::removeHead() {
    Node* temp = head;
    head = temp->next;
    delete temp;
}

void List::removeTail() {
    Node* temp = head;
    Node* prev = nullptr;
    if (head != nullptr){
        while (temp->next != nullptr){
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        delete temp;
    }
}

int List::get(int index) {
    Node* temp = head;
    int i = 0;
    if (head != nullptr){
        while (temp->next != nullptr && index != i){
            ++i;
            temp = temp->next;
        }
        return temp->data;

    }

    return -1;
}