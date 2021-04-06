#include <iostream>
#include "SinglyLinkedList.cpp"

int main(){
    List<int> list;
    list.append(12);
    list.prepend(21);
    list.insert(1, 1231);
    list.append(21);//
    // list.clear();
    list.show();
    return 0;
}