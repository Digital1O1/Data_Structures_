# [Linked List | Set 1 (Introduction)](https://www.geeksforgeeks.org/linked-list-set-1-introduction/)

# Overview

## Unlike arrays
- Linked list elements NOT stored at contiguous location
- Elements are linked using POINTERS

<br>

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist.png)

<br>

---

<br>

## Why linked lists?

### Arrays can store linear data of the same type, but they have limitations
- Size of array are fixed
  - You have to know upper limit of elements in advance
  - The allocated memory is equal to the upper limit
- Inserting/deleting a new element in an existing array is EXPENSIVE
  - Room has to be made for new elements
  - The existing elements have to be shifted
  - But with linked lists, the head node can traverse through any node
    - Can also insert new node at required position 


<br>

---

<br>

## Advantages over Arrays
- Dynamically sized
- Easy to insert/delete elements


<br>

---

## Drawbacks 
- Random access elements isn't allowed
  - Can only access elements sequentially from the first node
  - Can't do binary search with Linked Lists (LL)
- Extra space for pointer is needed with each element of the list
- Not cache friendly
  - Since each array element has it's own contiguous memory/location
- Takes alot of time traversing/changing the pointers
- Traversing in reverse isn't possible in SINGLY linked lists
- Direct access isn't possible in linked list
- Searching for a element is **costly** 
	- Also requires 0(n) time complexity
- Sorting linked list --> Very complex and costly

<br>

---

## Representation 

### Each node consists of two parts
- A data item
  - Int/String/Any type of data
- A pointer/reference to the next node
  - Or the address of another node

<br>

---

### Below is an example of a Linked List node with integer data

```cpp
class Node 
{
    public:
        int data;
        Node* next;
};
```
<br>

---

### Example of a simple linked list with three nodes
```cpp

// A simple CPP program to introduce
// a linked list
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

// Program to create a simple linked
// list with 3 nodes
int main()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	// allocate 3 nodes in the heap
	head = new Node();
	second = new Node();
	third = new Node();

	/* Three blocks have been allocated dynamically.
	We have pointers to these three blocks as head,
	second and third	
	head		 second		 third
		|			 |			 |
		|			 |			 |
	+---+-----+	 +----+----+	 +----+----+
	| # | # |	 | # | # |	 | # | # |
	+---+-----+	 +----+----+	 +----+----+
	
	# represents any random value.
	Data is random because we haven’t assigned
	anything yet */

	head->data = 1; // assign data in first node
	head->next = second; // Link first node with
	// the second node

	/* data has been assigned to the data part of first
	block (block pointed by the head). And next
	pointer of the first block points to second.
	So they both are linked.

	head		 second		 third
		|			 |			 |
		|			 |			 |
	+---+---+	 +----+----+	 +-----+----+
	| 1 | o----->| # | # |	 | # | # |
	+---+---+	 +----+----+	 +-----+----+	
*/

	// assign data to second node
	second->data = 2;

	// Link second node with the third node
	second->next = third;

	/* data has been assigned to the data part of the second
	block (block pointed by second). And next
	pointer of the second block points to the third
	block. So all three blocks are linked.
	
	head		 second		 third
		|			 |			 |
		|			 |			 |
	+---+---+	 +---+---+	 +----+----+
	| 1 | o----->| 2 | o-----> | # | # |
	+---+---+	 +---+---+	 +----+----+	 */

	third->data = 3; // assign data to third node
	third->next = NULL;

	/* data has been assigned to the data part of the third
	block (block pointed by third). And next pointer
	of the third block is made NULL to indicate
	that the linked list is terminated here.

	We have the linked list ready.

		head	
			|
			|
		+---+---+	 +---+---+	 +----+------+
		| 1 | o----->| 2 | o-----> | 3 | NULL |
		+---+---+	 +---+---+	 +----+------+	
	
	
	Note that only the head is sufficient to represent
	the whole list. We can traverse the complete
	list by following the next pointers. */

	return 0;
}

// This code is contributed by rathbhupendra

```

## Traversal of a linked list 

```cpp
// A simple C++ program for
// traversal of a linked list

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

// This function prints contents of linked list
// starting from the given node
void printList(Node* n)
{
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
}

// Driver's code
int main()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	// allocate 3 nodes in the heap
	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1; // assign data in first node
	head->next = second; // Link first node with second

	second->data = 2; // assign data to second node
	second->next = third;

	third->data = 3; // assign data to third node
	third->next = NULL;

	// Function call
	printList(head);

	return 0;
}

// This is code is contributed by rathbhupendra


```
![image](https://user-images.githubusercontent.com/39348633/215638144-ab98a848-a60c-4834-b888-bbde8b5d5055.png)
