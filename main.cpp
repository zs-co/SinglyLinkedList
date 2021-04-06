#include <iostream>
#include "LinkedList.h"

int main(){
    List list;
    list.append(32);
    list.append(322);
    list.append(900);
    list.append(99);
    std::cout << "get = " << list.get(1) << std::endl;
    list.removeTail();
    list.removeHead();
    list.show();
    return 0;
}