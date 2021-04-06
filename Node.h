#ifndef Node_H_LinkedList
#endif //NNode_H_LinkedList

class Node{
public:
    int data;
    Node* next; // address of next node.

    Node(){
        data = 0;
        next = nullptr;
    }
};