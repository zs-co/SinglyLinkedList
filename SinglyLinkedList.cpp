#include "LinkedList.h"
#include <iostream>
#include <typeinfo>
#include <cstring>

template <typename T>
void List<T>::append(T data) {
    auto *temp = new Node<T>();
    temp->data = data;
    temp->next = nullptr;
    if (this->head == nullptr){
        this->head = temp;
        this->tail = temp;
        ++this->size;
        return;
    }

    Node<T> *node = head;
    while (node->next != nullptr){
        node = node->next;
    }
    node->next = temp;
    tail = temp->next;
    ++size;
    //std::cout << tail->data << std::endl;
}
template <typename T>
void List<T>::show(){
    Node<T>* temp = head;
    while (temp != nullptr){
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

template <typename T>
void List<T>::prepend(T data) {
    auto *temp = new Node<T>();
    Node<T>* node = head;
    temp->data = data;
    temp->next = node;
    head = temp;
    ++size;
}

template <typename T>
void List<T>::remove(int index) {
    int i = 0;
    Node<T>* temp = head;
    Node<T>* prev = nullptr;
    if (head != nullptr){
        if (index <= 0){
            removeHead();
            --size;
            return;
        }
        while (temp != nullptr && index != i){
            prev = temp;
            temp = temp->next;
            ++i;
        }
        if (i < index)
            return;
        prev->next = temp->next;
        delete temp;
        --size;

    }
}

template <typename T>
void List<T>::removeHead() {
    Node<T>* temp = head;
    if (temp == nullptr)
        return;
    head = temp->next;
    delete temp;
    --size;
}

template <typename T>
void List<T>::removeTail() {
    Node<T>* temp = head;
    Node<T>* prev = nullptr;
    if (head == nullptr)
        return;

    if (head->next == nullptr)
    {
        --size;
        removeHead();
        return;
    }


    while (temp->next != nullptr){
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    delete temp;
    --size;
}

template <typename T>
T List<T>::get(int index) const {
    Node<T>* temp = head;
    T nothing;
    int i = 0;
    if (head != nullptr){
        while (temp->next != nullptr && index != i){
            ++i;
            temp = temp->next;
        }

        if (i == index)
            return temp->data;
    }
    return T{};


}

template <typename T>
int List<T>::getIndexOf(T value) {
    Node<T>* temp = head;
    int index = 0;
    if (temp != nullptr){
        while (temp->next != nullptr && temp->data != value){
            ++index;
            temp = temp->next;
        }

        if (temp->data == value)
            return index;
    }
    return -1;
}

template <typename T>
int List<T>:: len(){
    return this->size;
}

template <typename T>
int List<T>::getIndexOfTail() {
    return this->size - 1;
}

template <typename T>
int List<T>::getIndexOfHead() {
    return 0;
}

template <typename T>
void List<T>::update(int index, T value) {
    Node<T>* temp = head;
    if (temp == nullptr)
        return;
    int i = 0;
    while (temp->next != nullptr && i != index){
        temp = temp->next;
        i++;
    }

    if (i == index){
        temp->data = value;
    }
}

template <typename T>
void List<T>::insert(int index, T value) {
    auto *node = new Node<T>();
    node->data = value;
    Node<T>* temp = head;
    Node<T>* prev = nullptr;
    int i = 0;
    if (temp == nullptr || index <= 0){
        prepend(value);
        return;
    }
    while (temp != nullptr && i != index){
        i++;
        prev = temp;
        temp = temp->next;
    }

    if (i == index){
        prev->next = node;
        node->next = temp;
        return;
    }
    append(value);
}

template <typename T>
T List<T>::getFirst() {
    Node<T>* temp = head;
    if (temp != nullptr){
        return head->data;
    }
    return -1;
}

template <typename T>
T List<T>::getLast() {
    return get(getIndexOfTail());
}

template <typename T>
int List<T>::getLastIndexOf(T value) {
    int lastIndex = -1; //negative means no index is selected.
    int index = 0; // first index.
    Node<T>* temp = head;
    if (temp != nullptr){
        while (temp != nullptr){
            if (temp->data == value)
                lastIndex = index;
            ++index;
            temp = temp->next;
        }
    }
    return lastIndex;
}

template <typename T>
void List<T>::clear() {
    Node<T>* temp = this->head;
    while (temp->next != nullptr)
    {
       Node<T>* prev = temp;
        delete prev;
        temp = temp->next;
    }

    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}