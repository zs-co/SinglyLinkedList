#include <iostream>
#include "Node.h"
template <typename datatype>
class List{
public:
    int size;
    Node<datatype> *head;
    Node<datatype> *tail;
    Node<datatype> *prev;

    explicit List(){
        head = nullptr;
        tail = nullptr;
        prev = nullptr;
        size = 0;
    }

    int getIndexOfTail();
    int getIndexOfHead();
    void prepend(datatype);
    void append(datatype);
    void remove(int index);
    void show(const bool reverse);
    void show();
    void removeHead();
    void removeTail();
    datatype get(int index) const;
    int getIndexOf(datatype value);
    int len();
    void update(int, datatype);
    void insert(int index, datatype value);
    datatype getFirst() const;
    datatype getLast();
    int getLastIndexOf(datatype value);
    void clear();

};
