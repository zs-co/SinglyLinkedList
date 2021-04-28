#include "LinkedList.h"

template <typename T>
void List<T>::append(T _value) {
    auto node = new Node<T>;
    node->data = _value;
    node->next = nullptr;
    node->prev = nullptr;

    if (this->head == nullptr) {
        this->head = node;
        this->tail = node;
    }
    else {
        Node<T>* temp = this->head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
        this->tail = node;// adds address of node in tail as well .
    }
    this->size++; //updated size...
}

template <typename T>
void List<T>::prepend(T _value) {
    auto *temp = new Node<T>();
    temp->data = _value;
    temp->prev = nullptr;
    temp->next = nullptr; // attributes are set....
    if (this->head == nullptr) {
        append(_value);
    }
    else {
        temp->next = this->head;
        this->head->prev = temp;
        this->head = temp; //updated head.
        ++this->size;
    }

}


template<typename T>
int List<T>::getIndexOfHead() {
    if (this->head == nullptr)
        return -1;
    return 0;
}

template<typename T>
int List<T>::getIndexOfTail() {
    return this->size - 1;
}

template <typename T>
int List<T>::len() {
    return this->size; //size of the list.
}

template <typename T>
T List<T>::getFirst() const {
    return this->head->data;
}

template <typename T>
T List<T>::getLast() {
    return this->tail->data;
}

template<typename T>
T List<T>::get(int _index) const{
    if (_index >= size || _index < 0) {
        std::cerr << "Index out of bound!";
        return T{};
    }
    else {
        auto *node = this->head;
        int i = 0;
        while (node != nullptr) {
            if (i == _index) {
                return node->data;
            }
            node = node->next;
            i++; //increment.
        }

    }
}

template <typename T>
void List<T>::insert(int index, T value) {
    auto *node = new Node<T>();
    node->data = value;
    int i = 0;
    if (this->head != nullptr && index > 0) {
        if (index >= this->size) {
            this->append(value);
        }
        else {
            Node<T> *temp = this->head;
            while (temp != nullptr) {
                if (i == (index)) {
                    node->next = temp;
                    node->prev = temp->prev;
                    temp->prev = node;
                    break;
                }
                i++;
                temp = temp->next;
            }
        }
    }
    else {
        this->prepend(value);
    }
}

template <typename T>
void List<T>::update(int index, T newValue) {
    if (this->head != nullptr || index >= 0) {
        int i = 0;
        auto *temp = this->head;
        while (temp->next != nullptr) {
            if (i == index) {
                temp->data = newValue;
                break;
            }
            i++;
            temp = temp->next;
        }
    }
}

template <typename T>
void List<T>::show(const bool isReversed) {
    Node<T>* node;
    if (isReversed) {
       node = this->tail;
        while (node != nullptr){
            std::cout << node->data << ", ";
            node = node->prev;
        }
        return;
    }
    node = this->head;
    while (node != nullptr) {
        std::cout << node->data << ", ";
        node = node->next;
    }
}

template <typename T>
void List<T>::remove(int index) {
    int i = 0;
    auto *node = this->head;
    Node<T> *temp = nullptr;
    if (this->head == nullptr || index == 0) {
        removeHead();
    }
    else {
        while (node != nullptr) {
            if (i == index) {
                auto *temp1 = node->next;
                temp->next = temp1->next;
                temp1->prev = temp;
                delete node;
                break;
            }
            i++;
            temp = node;
            node = node->next;
        }
    }
}

template <typename T>
void List<T>::removeHead() {
    auto *node = this->head;
    this->head = node->next;
    node->prev = nullptr;
    delete node;
}

template <typename T>
void List<T>::clear() {
    auto *node = this->head;
    while (node != nullptr) {
         Node<T> *temp = node;
         node = node->next;
         delete temp;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0; // list is fully empty now.
}