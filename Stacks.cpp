#include "LinkedList.h"

template <typename T>
class Stack{
    int size;
    List<T> list;
public:
    Stack() {
        this->size = 0;
    }
    void push(const T& value);
    void pop() const ;
    T peek() const ;
    bool isEmpty() const;
    void clear();

};

template <typename T>
bool Stack<T>::isEmpty() const {
    if (this->size == 0)
        return true;
    return false;
}

template <typename T>
void Stack<T>::pop() const {
    this->list.removeHead();
}

template <typename T>
T Stack<T>::peek() const {
    return this->list->getLast();
}

template <typename T>
void Stack<T>::push(const T& value) {
    this->list->append(value);
}

template <typename T>
void Stack<T>::clear() {
    this->list.clear();
}