# [Linked List | Set 2 (Inserting a node)](https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/)

   
<br>

# Overview
## Three methods to insert a new node in a Linked List
    1) At the front of the linked list  
    2) After a given node. 
    3) At the end of the linked list.
   
<br>

# Adding a node at the front | Four step process 
## push() function
- Time complexity = O(1) : Does a constant amount of work

<br>

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_at_start.png)

```cpp
/* Given a reference (pointer to pointer) 
to the head of a list and an int, 
inserts a new node on the front of the list. */
void push(Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    Node* new_node = new Node(); 
  in
    /* 2. put in the data */
    new_node->data = new_data; 
  
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref); 
  
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node; 
} 
```
<br>

# Adding a node after a given node | Five step process

<br>

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_middle.png)

<br>

```cpp
// Given a node prev_node, insert a
// new node after the given
// prev_node
void insertAfter(Node* prev_node, int new_data)
{
  
    // 1. Check if the given prev_node is NULL
    if (prev_node == NULL) 
    {
        cout << "The given previous node cannot be NULL";
        return;
    }
  
    // 2. Allocate new node
    Node* new_node = new Node();
  
    // Insert new_data into 'new_node'
    // 3. Put in the data
    new_node->data = new_data;

    /*
        Reference : https://www.youtube.com/watch?v=RNMIDj62o_o&ab_channel=CodeBeauty
        Example... There's three nodes
            - Node A (First node)
            - New Node (Node to be inserted)
            - Node B ('Last' node )

         new_node->next = prev_node->next;
            - This will make new_node point towards Node B
            - new_node --> node_B

         prev_node->next = new_node;
            - Node A will POINT to the new_node/new connection
    */
  
    // 4. Make next of new node as next of prev_node
    // Reference link : https://www.geeksforgeeks.org/insertion-in-linked-list/
    // New node points to whatever the previous node was pointing to aka Node B
    new_node->next = prev_node->next;
  
    // 5. move the next of prev_node as new_node
    // This is the arrow that's going from B --> E 

    prev_node->next = new_node;
}
```
<br>

# Add a node at the end: 6 steps process 

<br>

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist_insert_last.png)

```cpp

// Given a reference (pointer to pointer) to the head  
// of a list and an int, appends a new node at the end 
void append(Node** head_ref, int new_data)  
{  
    
    // 1. allocate node 
    Node* new_node = new Node(); 
    
    // Have the head_ref pointer point towards the last node
    Node *last = *head_ref; 
    
    // 2. Put in the data 
    new_node->data = new_data;  
    
    // 3. This new node is going to be  
    // the last node, so make next of  
    // it as NULL
    new_node->next = NULL;  
    
    // 4. If the Linked List is empty, 
    // then make the new node as head 
    if (*head_ref == NULL)  
    {  
        *head_ref = new_node;  
        return;  
    }  
    
    // 5. Else traverse till the last node 
    while (last->next != NULL)
    {
        last = last->next;  
    }
    
    // 6. Change the next of last node 
    last->next = new_node;  
    return;  
}  

```
<br>

# Entire Program

```cpp
using namespace std;
  
// A linked list node 
class Node 
{ 
    public:
    int data; 
    Node *next; 
}; 
  
/* 
    Given a reference (pointer to pointer)
    to the head of a list and an int, inserts
    a new node on the front of the list. 
*/
void push(Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    Node* new_node = new Node();
  
    /* 2. put in the data */
    new_node->data = new_data; 
  
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref); 
  
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node; 
} 
  
/* Given a node prev_node, insert a new node after the given 
prev_node */
void insertAfter(Node* prev_node, int new_data) 
{ 
    /* References 
        https://www.youtube.com/watch?v=zK-qTBWozcY&ab_channel=CodeVault
        https://www.youtube.com/watch?v=g8VLr7UGsZo&ab_channel=ArpanPathak
        https://www.youtube.com/watch?v=0hGxILnKvJk&ab_channel=NesoAcademy
    */
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) 
    { 
        cout<<"The given previous node cannot be NULL"; 
        return; 
    } 
  
    /* 2. allocate new node */
    Node* new_node = new Node();
  
    /* 3. put in the data */
    new_node->data = new_data; 
  
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next; 
  
    /* 5. move the next of prev_node as new_node */
    // Remember : next is the pointer variable
    // Connect prev_node to new_node
    prev_node->next = new_node; 
} 
  
/* Given a reference (pointer to pointer) to the head 
of a list and an int, appends a new node at the end */
void append(Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    Node* new_node = new Node();
  
    Node *last = *head_ref; /* used in step 5*/
  
    /* 2. put in the data */
    new_node->data = new_data; 
  
    /* 3. This new node is going to be 
    the last node, so make next of 
    it as NULL*/
    new_node->next = NULL; 
  
    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL) 
    { 
        *head_ref = new_node; 
        return; 
    } 
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
    {
        last = last->next; 
    }
  
    /* 6. Change the next of last node */
    /*
        Have the last node point towards the new_node that's already pointing towards NULL
    */
    last->next = new_node; 
    return; 
} 
  
// This function prints contents of
// linked list starting from head 
void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        cout<<" "<<node->data; 
        node = node->next; 
    } 
} 
  
/* Driver code*/
int main() 
{ 
    /* Start with the empty list */
    Node* head = NULL; 
      
    // Insert 6. So linked list becomes 6->NULL 
    append(&head, 6); 
      
    // Insert 7 at the beginning. 
    // So linked list becomes 7->6->NULL 
    push(&head, 7); 
      
    // Insert 1 at the beginning. 
    // So linked list becomes 1->7->6->NULL 
    push(&head, 1); 
      
    // Insert 4 at the end. So 
    // linked list becomes 1->7->6->4->NULL 
    append(&head, 4); 
      
    // Insert 8, after 7. So linked 
    // list becomes 1->7->8->6->4->NULL 
    insertAfter(head->next, 8); 
      
    cout<<"Created Linked list is: "; 
    printList(head); 
      
    return 0; 
} 
  
Created Linked list is:  1  7  8  6  4
```