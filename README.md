# 🌀 Singly Linked List from Scratch  
*C++ Project by Mohamed Owaymr*  

---

## 🌟 Situation  
Learning data structures is more fun when you **build them yourself**! Instead of using built-in containers like `std::list`, I decided to dive into the world of pointers, memory, and dynamic data by implementing a **singly linked list** from scratch.  

---

## 🎯 Task  
I wanted to create a **fully-functional linked list** in C++ that could:  

- 📝 Insert elements at the head or tail  
- ❌ Delete elements by value or position  
- 🔍 Search for a specific value  
- 🔄 Reverse the list  
- 🗑️ Clear the list completely  

All while keeping **memory safe** and **code clean**.  

---

## 🚀 Action  
Here’s what I did:  

1. 🔹 Created `Node` and `LinkedList` classes.  
2. 🔹 Implemented all core operations: insertion, deletion, searching, reversing, and clearing.  
3. 🔹 Managed dynamic memory carefully using `new` and `delete`.  
4. 🔹 Split code into **header files** for better organization:  
   - `Node.hpp` – defines the structure of a node  
   - `LinkedList.hpp` – main linked list class  
5. 🔹 Added **test cases** in `Test.cpp` to test my Linked List class.  
6. 🔹 Documented each method with comments for easier understanding.  

---

## 🏆 Result  
✅ A **working, reusable singly linked list** in C++  
✅ Improved understanding of **pointers, memory, and list algorithms**  
✅ Ready to use as a **learning tool** or as a base for more advanced data structures  

---

## ⚡ Getting Started  

### Prerequisites  
- C++ compiler supporting C++11+ (`g++`, `clang++`)  
- Basic knowledge of pointers & dynamic memory  

### How to Run  
```bash
git clone https://github.com/Mohamed-Owaymr/Implementing-a-Singly-Linked-List-from-Scratch.git
cd Implementing-a-Singly-Linked-List-from-Scratch
g++ -std=c++11 Test.cpp -o Test
./Test
```

---

## 📂 Project Structure  

```
HeaderFiles/
├── Node.hpp       ← Node class
├── LinkedList.hpp ← LinkedList class
Test.cpp           ← Test & demonstration
README.md          ← This file
```

---

## 💡 Fun Examples  

- Create a list:  
```cpp
LinkedList<int> list;
list.insertAtHead(10);
list.insertAtTail(20);
list.print();
```

- Reverse it:  
```cpp
list.reverse();
list.print();
```

- Delete a value:  
```cpp
list.deleteValue(10);
list.print();
```

---

## 🎉 Conclusion  
Building a linked list from scratch was a **fun and educational journey**! It helped me strengthen my C++ skills and better understand how lists work **under the hood**.  

---

![Fun Coding GIF](https://media.giphy.com/media/3o7aCVppL2OD2rE4vG/giphy.gif)

