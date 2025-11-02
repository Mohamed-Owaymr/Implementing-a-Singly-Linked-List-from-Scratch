#pragma once
using namespace std;

template <typename Type>
class Node {
private:
    Type data;
    Node<Type>* next;

public:
    Type getData() const {
        return data; 
    }
    void setData(const Type& data) {
        this->data = data; 
    }
    Node<Type>* getNext() const {
        return next; 
    }
    void setNext(Node<Type>* next) {
        this->next = next; 
    }    

public:
    Node(const Type& data) : data(data) {
        next = nullptr;
    }


};