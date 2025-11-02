#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <typename Type>
class LinkedList {
private:
    Node<Type>* head;
    size_t size;

public:
    // Hidden Functions Declaration
    Node<Type>* insertNodeAtHead(Node<Type>* nodeToInsert);
    Node<Type>* insertNodeAtTail(Node<Type>* nodeToInsert);
    Node<Type>* insertAtPosition(Node<Type>* nodeToInsert , const size_t& position);
    size_t findNodePositionByValue(const Type& value) const;
    Node<Type>* findNodeByPosition(const size_t& position) const;
    Node<Type>* findTailNode() const;
    Node<Type>* findMinNode() const;
    Node<Type>* findMaxNode() const;
    Node<Type>* reverseUsingIterative();
    Node<Type>* split(Node<Type>* head);
    Node<Type>* mergeWithOrder(Node<Type>* first , Node<Type>* second);
    Node<Type>* mergeSort(Node<Type>* head);

public:
    // Constructor Declaration
    LinkedList();

    // Getters Declaration
    Type getHead() const;
    Type getTail() const;
    size_t getSize() const;

    // Core Functions Declaration
    void insertAtHead(const Type& value);
    void insertAtTail(const Type& value);
    void insertAtPosition(const Type& value , const size_t& position);
    void deleteHead();
    void deleteTail();
    void deleteAtPosition(const size_t& position);
    void clear();
    

    // Utility Functions Declaration
    size_t findByValue(const Type& value) const;
    Type findByPosition(const size_t& position) const;
    Type findMin() const;
    Type findMax() const;
    void reverse();
    void sort();
    bool isEmpty() const;


    //Destructor Declaration
    ~LinkedList();
};



// ========== IMPLEMENTATION PART ==========

// Constructor Implementation
template <typename Type>
LinkedList<Type>::LinkedList() {
    head = nullptr;
    size = 0;
}

// Getters Implementation
template <typename Type>
Type LinkedList<Type>::getHead() const {
    if(isEmpty()) {
        runtime_error("Cannot find in empty list!");
    }
    return head->getData();
}
template <typename Type>
Type LinkedList<Type>::getTail() const {
    Node<Type>* tailNode = findTailNode();
    return tailNode->getData();
}
template <typename Type>
size_t LinkedList<Type>::getSize() const {
    return size;
}


// Hidden Functions Implementation
template <typename Type>
Node<Type>* LinkedList<Type>::insertNodeAtHead(Node<Type>* nodeToInsert) {
    if(nodeToInsert == nullptr) {
        throw invalid_argument("Cannot insert a null node!");
    }

    if(!isEmpty()) {
        nodeToInsert->setNext(head);
    }

    head = nodeToInsert;
    ++size;
    return head;
}
template <typename Type>
Node<Type>* LinkedList<Type>::insertNodeAtTail(Node<Type>* nodeToInsert) {
    if(nodeToInsert == nullptr) {
        throw invalid_argument("Cannot insert a null node!");
    }

    if(isEmpty()) {
        head = nodeToInsert;
        ++size;
        return head;
    }

    Node<Type>* tailNode = findTailNode();
    tailNode->setNext(nodeToInsert);
    ++size; 
    return head;
}
template <typename Type>
Node<Type>* LinkedList<Type>::insertAtPosition(Node<Type>* nodeToInsert, const size_t& position) {
    if (nodeToInsert == nullptr) {
        throw invalid_argument("Cannot insert a null node!");
    }

    if (position == 1) {
        return insertNodeAtHead(nodeToInsert);
    }

    Node<Type>* previousNode = findNodeByPosition(position - 1);

    if (previousNode == nullptr) {
        throw out_of_range("Invalid position!");
    }

    nodeToInsert->setNext(previousNode->getNext());
    previousNode->setNext(nodeToInsert);
    ++size;

    return head;
}
template <typename Type>
size_t LinkedList<Type>::findNodePositionByValue(const Type& value) const {
    if(isEmpty()) {
        return 0;
    }

    size_t position = 1;
    Node<Type>* currentNode = head;
    while(currentNode != nullptr) {
        if(currentNode->getData() == value) {
            return position;
        }
        currentNode = currentNode->getNext();
        ++position;
    }
    return 0;
}
template <typename Type>
Node<Type>* LinkedList<Type>::findNodeByPosition(const size_t& position) const {
    if(isEmpty()) {
        throw runtime_error("Cannot find in empty list!");
    }

    if(position < 1 || position > size) {
        throw invalid_argument("Cannot find list , Position out of range");
    }

    if(position == 1) {
        return head;
    }

    Node<Type>* currentNode = head;
    for(size_t i = 1; i < position; ++i) {
        currentNode = currentNode->getNext();
    }

    return currentNode;
}
template <typename Type>
Node<Type>* LinkedList<Type>::findTailNode() const {
    if(isEmpty()) {
        throw runtime_error("Cannot find in empty list!");
    }

    Node<Type>* currentNode = head;
    while (currentNode->getNext() != nullptr) {
        currentNode = currentNode->getNext();
    }
    
    return currentNode;
}
template <typename Type>
Node<Type>* LinkedList<Type>::findMinNode() const {
    if(isEmpty()) {
        throw runtime_error("Cannot find in empty list!");
    }
    Node<Type>* current = head;
    Node<Type>* min = head;
    while (current != nullptr)
    {
        if(current->getData() < min->getData()) {
            min = current;
        }
        current = current->getNext();
    }
    return min;
    
}
template <typename Type>
Node<Type>* LinkedList<Type>::findMaxNode() const {
    if(isEmpty()) {
        throw runtime_error("Cannot find in empty list!");
    }
    Node<Type>* current = head;
    Node<Type>* max = head;
    while (current != nullptr)
    {
        if(current->getData() > max->getData()) {
            max = current;
        }
        current = current->getNext();
    }
    return max;
}
template <typename Type>
Node<Type>* LinkedList<Type>::reverseUsingIterative() {
    if(isEmpty() || size == 1) {
        return head;
    }

    Node<Type>* previos = nullptr;
    Node<Type>* current = head;
    Node<Type>* next    = current->getNext();

    while (current != nullptr)
    {       
        current->setNext(previos);
        
        previos = current;
        current = next;
        
        if(next != nullptr)
            next = current->getNext();
    }
    
    head = previos;
    return head;
}

template <typename Type>
Node<Type>* LinkedList<Type>::split(Node<Type>* head) {
    if(head == nullptr || head->getNext() == nullptr) {
        return head;
    }

    Node<Type>* fast = head;
    Node<Type>* slow = head;

    while (fast != nullptr && fast->getNext() != nullptr)
    {
        fast = fast->getNext()->getNext();
        if(fast != nullptr) {
            slow = slow->getNext();
        }
    }

    Node<Type>* temporary = slow->getNext();
    slow->setNext(nullptr);
    
    return temporary;
}


template <typename Type>
Node<Type>* LinkedList<Type>::mergeWithOrder(Node<Type>* first , Node<Type>* second) {
    if(first == nullptr) return second;
    if(second == nullptr) return first;

    if(first->getData() < second->getData()) {
        first->setNext(mergeWithOrder(first->getNext() , second));
        return first;
    } else {
        second->setNext(mergeWithOrder(first , second->getNext()));
        return second;
    }
}

template <typename Type>
Node<Type>* LinkedList<Type>::mergeSort(Node<Type>* head) {
    if(head == nullptr || head->getNext() == nullptr)
        return head;

    Node<Type>* secondSublist = split(head);

    head = mergeSort(head);
    secondSublist = mergeSort(secondSublist);

    return mergeWithOrder(head , secondSublist);
}





// Core Functions Implementation
template <typename Type>
void LinkedList<Type>::insertAtHead(const Type& value) {
    Node<Type>* nodeToInsert = new Node<Type>(value);
    insertNodeAtHead(nodeToInsert);
}
template <typename Type>
void LinkedList<Type>::insertAtTail(const Type& value) {
    Node<Type>* nodeToInsert = new Node<Type>(value);
    insertNodeAtTail(nodeToInsert);

}
template <typename Type>
void LinkedList<Type>::insertAtPosition(const Type& value , const size_t& position) {
    Node<Type>* nodeToInsert = new Node<Type>(value);
    insertAtPosition(nodeToInsert , position);
}

template <typename Type>
void LinkedList<Type>::deleteHead() {
    if(isEmpty()) {
        throw runtime_error("Cannot delete from empty list");
    }

    Node<Type>* headTemporary = head;
    head = head->getNext();
    delete headTemporary;
    --size;
}
template <typename Type>
void LinkedList<Type>::deleteTail() {
    if(isEmpty()) {
        throw runtime_error("Cannot delete from empty list");
    }
    if(size == 1) {
        delete head;
        head = nullptr;
        --size;
        return;
    }
    Node<Type>* previousNode = head;
    while (previousNode->getNext()->getNext() != nullptr)
    {
        previousNode = previousNode->getNext();
    }
    Node<Type>* tailNodeToDelete = previousNode->getNext();
    delete tailNodeToDelete;
    previousNode->setNext(nullptr);
    --size;
}
template <typename Type>
void LinkedList<Type>::deleteAtPosition(const size_t& position) {
    if(isEmpty()) {
        throw runtime_error("Cannot delete from empty list");
    }

    if(position > size || position < 1) {
        throw invalid_argument("Cannot delete list , Position out of range");
    }

    if(position == 1) {
        return deleteHead();
    }

    Node<Type>* previousNode = findNodeByPosition(position - 1);
    Node<Type>* nodeToDelete = previousNode->getNext();
    previousNode->setNext(nodeToDelete->getNext());
    delete nodeToDelete;
    --size;
}
template <typename Type>
void LinkedList<Type>::clear() {
    while (!isEmpty())
    {
        deleteHead();
    }
}


// Utility Functions Implementation
template <typename Type>
size_t LinkedList<Type>::findByValue(const Type& value) const {
    return findNodePositionByValue(value);
}
template <typename Type>
Type LinkedList<Type>::findByPosition(const size_t& position) const {
     Node<Type>* node = findNodeByPosition(position);
    return node->getData();
}
template <typename Type>
Type LinkedList<Type>::findMin() const {
    return findMinNode()->getData();
}
template <typename Type>
Type LinkedList<Type>::findMax() const{
    return findMaxNode()->getData();
}
template <typename Type>
void LinkedList<Type>::reverse() {
    reverseUsingIterative();
}


template <typename Type>
void LinkedList<Type>::sort() {
    head = mergeSort(head);
}

template <typename Type>
bool LinkedList<Type>::isEmpty() const {
    return head == nullptr;
}

//Destructor Implementation
template <typename Type>
LinkedList<Type>::~LinkedList() {
    clear();
}

