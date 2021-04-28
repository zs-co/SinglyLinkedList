#include <iostream>
//#include "SinglyLinkedList.cpp"
#include "DoublyLinkedList.cpp"
//#include <string>
//#include "Stacks.cpp"

int main(){
    List<int> list;
//    Stack<int> stack;
//    stack.isEmpty();
    /*
    list.append(12) ;
    list.prepend(21);
    list.show(false);
    std::cout << "\n-----------Reversed-----------" << std::endl;
    list.show(true); */
    /*
     * std::cout << "First = " << list.getFirst();
       std::cout << "\nLast = " << list.getLast(); */
    //std::cout << "Value at 100 = " << list.get(10);
    list.insert(0, 100);
    list.prepend(12);
    list.append(20);
    list.insert(2, 90);
   // list.insert(1, 200);
    list.append(21);
    list.update(2, 125);
//    list.remove(1);
//    list.remove(2);
//    list.remove(0);
    std::cout << "\nSize of the list is = " << list.len() << std::endl;
    list.clear();
    list.insert(0,20);
    list.insert(1, 90);
    list.insert(1,99);
    list.show(false);

    return 0;
}