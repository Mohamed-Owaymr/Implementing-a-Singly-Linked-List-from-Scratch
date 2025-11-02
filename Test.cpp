#include <iostream>
#include <stdexcept>
#include "HeaderFiles/LinkedList.h"
using namespace std;

template <typename T>
void printList(LinkedList<T>& list) {
    cout << "[ ";
    for (size_t i = 1; i <= list.getSize(); ++i) {
        cout << list.findByPosition(i);
        if (i < list.getSize()) cout << " -> ";
    }
    cout << " ] (size=" << list.getSize() << ")" << endl;
}


// Main Function to Test Linked List Class
int main() {
    LinkedList<int> list;
    cout << "\n==== LINKED LIST AUTOMATED TEST REPORT ====\n";
    int testCount = 0, passCount = 0;

    auto runTest = [&](bool condition, const string& testName, const string& message = "") {
        testCount++;
        if (condition) {
            cout << "[TEST #" << testCount << "] " << testName << ": ✅ Passed\n";
            passCount++;
        } else {
            cout << "[TEST #" << testCount << "] " << testName << ": ❌ Failed " << message << endl;
        }
    };

    // ================== INSERTION TESTS ==================
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30); // List: 30 -> 20 -> 10
    runTest(list.getHead() == 30, "InsertAtHead 3 elements");

    list.insertAtTail(5);
    list.insertAtTail(1); // 30 -> 20 -> 10 -> 5 -> 1
    runTest(list.getTail() == 1, "InsertAtTail");

    list.insertAtPosition(15, 4); // position 4
    runTest(list.findByPosition(4) == 15, "InsertAtPosition(4, 15)");

    // ================== FIND TESTS ==================
    runTest(list.findByValue(15) == 4, "FindByValue(15)");
    runTest(list.findByValue(999) == 0, "FindByValue(999)");

    runTest(list.findMin() == 1, "FindMin()");
    runTest(list.findMax() == 30, "FindMax()");

    // ================== DELETE TESTS ==================
    list.deleteHead(); // remove 30
    runTest(list.getHead() == 20, "DeleteHead()");

    list.deleteTail(); // remove 1
    runTest(list.getTail() == 5, "DeleteTail()");

    list.deleteAtPosition(3); // delete 15
    runTest(list.findByPosition(3) == 5, "DeleteAtPosition(3)");

    // ================== REVERSE TEST ==================
    int oldHead = list.getHead();
    list.reverse();
    runTest(list.getTail() == oldHead, "Reverse()");

    // ================== SORT TEST ==================
    list.sort();
    runTest(list.findMin() == 5 && list.findMax() == 20, "Sort()");

    // ================== CLEAR TEST ==================
    list.clear();
    runTest(list.getSize() == 0, "Clear()");
    runTest(list.isEmpty(), "IsEmpty after Clear()");

    // ================== EDGE EXCEPTIONS ==================
    try {
        list.deleteHead();
        runTest(false, "DeleteHead on Empty");
    } catch (...) {
        runTest(true, "DeleteHead on Empty throws");
    }

    try {
        list.deleteAtPosition(1);
        runTest(false, "DeleteAtPosition on Empty");
    } catch (...) {
        runTest(true, "DeleteAtPosition on Empty throws");
    }

    try {
        list.findByPosition(1);
        runTest(false, "FindByPosition on Empty");
    } catch (...) {
        runTest(true, "FindByPosition on Empty throws");
    }

    // ================== MASSIVE INSERTION ==================
    for (int i = 1; i <= 50; ++i)
        list.insertAtTail(i);
    runTest(list.getSize() == 50, "Mass Insert 50 elements");
    runTest(list.getHead() == 1 && list.getTail() == 50, "Mass Insert Head/Tail check");

    // ================== MASSIVE DELETE ==================
    for (int i = 0; i < 25; ++i)
        list.deleteHead();
    runTest(list.getSize() == 25, "Mass Delete 25 heads");

    for (int i = 0; i < 25; ++i)
        list.deleteTail();
    runTest(list.isEmpty(), "Mass Delete all");

    // ================== STRESS TEST ==================
    for (int i = 1; i <= 100; ++i) {
        if (i % 2 == 0) list.insertAtHead(i);
        else list.insertAtTail(i);
    }
    runTest(list.getSize() == 100, "Stress Insert 100 elements");
    list.reverse();
    list.sort();
    runTest(list.findMin() == 1 && list.findMax() == 100, "Stress Reverse + Sort");

    // ================== FINAL REPORT ==================
    cout << "\n==== TEST REPORT SUMMARY ====\n";
    cout << "Total Tests: " << testCount << endl;
    cout << "Passed: " << passCount << endl;
    cout << "Failed: " << (testCount - passCount) << endl;
    cout << "Success Rate: " << (passCount * 100.0 / testCount) << "% ✅\n";
    cout << "==============================\n";
    return 0;
}