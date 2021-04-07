#include <iostream>
#include "SinglyLinkedList.cpp"
#include <string>
int main(){
    List<int> list;
    list.append(98);
    list.append(21);
    list.insert(3,45);
    std::cout << list.getIndexOfTail() << std::endl;
    std::cout << list.get(10) << std::endl;
    std::cout << "List ..... " << std::endl;
   //std::cout <<  list.getLast() << "\n";
   list.removeHead();
   list.removeTail();
    list.show();

    return 0;
}