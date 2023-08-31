# Using a "Temproary" node
- Referred to as a dummy/sentinel node
- Used to simplify certain operations on LL
<br>

# Why using one can be useful
## 1) Simplifying Insertion/Deletion at beginning 
- When inserting/deleting a node a tthe beginning of a LL
    - You might need to update the head pointer
- Using a temporary node before the actual head lets you **<u> avoid </u>** handling the special case where the head pointer needs to change
    - For example : LIFO where elements are added/removed from the same 'end'
- Using one leads to more clearner/consistent code

## 2) Avoiding Special Cases
- Lets say....
    - You have a function that needs to insert a node at a specific position in the LL
    - Using a temp node **<u>BEFORE</u>** the desired position eliminates the need to differentiate between inserting at the beginning,middle or end of the list
        - This simplifies the logic
        - Reduces changes of introducing bugs

## 3) Avoid Null Pointer Checks
- Example : You're iterating through LL and need to perform an operation on EACH NODE
- Using a temporary node can ensure you always have a valid 'previous' node to work with
    - Even if you're at the beginning of the list

## 4) Uniform Algorithm Logic
- TL;DR : Using them makes your code easier to understand and maintain

<br>

# Code example : Simplifying inserting a node at the beginning of a list
```cpp
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    /* 
        Class constructor that initializes member variables of a class

        
    */
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(new Node(0)) {}

    void insertAtBeginning(int data) {
        Node* new_node = new Node(data);
        new_node->next = head->next;
        head->next = new_node;
    }
};

int main() {
    LinkedList linkedList;
    linkedList.insertAtBeginning(3);
    linkedList.insertAtBeginning(5);

    return 0;
}


```