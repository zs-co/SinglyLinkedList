#include <iostream>
#include "Node.h"
template <typename datatype>
class List{
public:
    int size = 0;
    Node<datatype> *head;
    Node<datatype> *tail;

    explicit List(){
        head = nullptr;
        tail = nullptr;
    }
    int getIndexOfTail();
    int getIndexOfHead();
    void prepend(datatype);
    void append(datatype);
    void remove(int index);
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
