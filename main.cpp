#include <iostream>
#include "SinglyLinkedList.cpp"
#include <string>
int main(){
    List<int> list;
    List<double> list1;
    list.append(10);
    list1.append(20);
    list.get(10);
    list1.get(21);
    List <char> ch;
    ch.append('a');
    ch.show();
    ch.get(2);
    list1.show();
    list.removeTail();
    list.show();

    return 0;
}