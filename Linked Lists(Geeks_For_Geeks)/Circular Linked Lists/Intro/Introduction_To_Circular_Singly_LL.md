# [What is a Circular Linked List](https://www.geeksforgeeks.org/circular-linked-list/#)

-   All nodes form a circle
-   First and last node **connected**
-   No **NULL** at the end

<br>

# Two types of circular linked lists

## Circular **SINGLY** Linked List

-   Last node of list has **pointer** to the first node of the list
-   When traversing the entire circular singly linked list will be from **start** to **end**
    -   Since there's no **NULL** value present

![image](https://github.com/Digital1O1/4_DOF_Robotic_Arm/assets/39348633/a0bf7c84-604f-484b-b51f-aaff2ded8631)

## Circular **DOUBLY** linked list

-   Has properties of **both** doubly/circular linked lists
    -   Two consecutive elements are linked/connected by the previous and next pointer
    -   The last node points to the first node
        -   By the next pointer
    -   The first node points to the last node
        -   By the previous pointer

![image](https://github.com/Digital1O1/4_DOF_Robotic_Arm/assets/39348633/2156ce1c-6193-4a04-bc5f-4a7a8a4d2727)

<br>

# Representation of circular SINGLY linked list:

```cpp
class Node
{
    public:
        // Store incoming data
        int value;
        // Points to the next node.
        Node *next;
}
```

# Example of Circular Singly Linked List

![image](https://github.com/Digital1O1/ESP32_MindWave_Project/assets/39348633/414a6fea-3e3c-43ab-a0b2-afba3b8be668)

```cpp

// Initialize the Nodes and add a value to them
Node one = new Node(3);
Node two = new Node(5);
Node three = new Node(9);

// Connect nodes | These 'interlink' the nodes to one another
// Variable to be changed = Destination
one->next = two;
two->next = three;
three->next = one;
```

<br>

# Operations on the circular linked list:

Operations on Circular that are similar to Singly

-   Insertion
-   Deletion

<br>

# Adding a node 3 ways

1. At the beginning of the list
2. At the end of the list
3. Between the nodes

<br>

## Insertion in an empty List:

```cpp
// C++ program for the above operation
Node *addToEmpty(Node *tail, int data)
{
    // This function is only for empty list
    if (tail != NULL)
        return tail;

    // Creating a node dynamically.
    Node *new_node = new Node();

    // Assigning the data.
    new_node->data = data;

    // Update tail pointer to point towards new_node
    tail = new_node;

    // Creating the link that loops around to the first node
    tail->next = tail;
    return tail;
}
```

<br>

## Insertion at the beginning of the list

### Circular linked list **BEFORE** insertion

![image](https://github.com/Digital1O1/OpenCV_4.7_RPI_Install/assets/39348633/4233f1a8-8708-488a-b6fc-e7dbb09b1333)

### After insertion

![image](https://github.com/Digital1O1/OpenCV_4.7_RPI_Install/assets/39348633/cde9ab3d-5ad4-4142-a03b-ef4e6acf3f46)
![image](https://github.com/Digital1O1/OpenCV_4.7_RPI_Install/assets/39348633/daa2de07-9bed-4a8c-8dac-8ac117df9e92)
<br>

### Code implementation add at beginning

```cpp
Node *addBegin(Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);

    // Creating a node dynamically.
    Node *temp = new Node();

    // Assigning the data.
    temp -> data = data;

    // Two things happen here 
    // 1) The temp node will be placed towards the front of the LL
    // 2) The temp node points to the next 'last' node
    temp -> next = last -> next;

    // This will have the 'last' pointer circle back to the newly inserted temp node
    last -> next = temp;

    return last;
}
```

<br>

## Inserting at the end of the list

```cpp
// C++ program for the above operation

Node* addEnd(Node* tail, int data)
{
    if (tail == NULL)
        return addToEmpty(tail, data);

    // Creating a node dynamically.
    Node* temp =  new Node();

    // Assigning the data.
    temp->data = data;

    // Have the incoming temp node point to the first element in the LL
    temp->next = last->next;

    // Have the very last node point towards the incoming temp node
    tail->next = temp;
    tail = temp->next;

    return tail;
}
```

### **<u>Before insertion</u>**

![image](https://github.com/Digital1O1/4_DOF_Robotic_Arm/assets/39348633/27de784c-61ca-4fd6-8293-9cc5906c4135)

### **<u>After insertion</u>**

![image](https://github.com/Digital1O1/4_DOF_Robotic_Arm/assets/39348633/d6dbb35e-7639-4b64-88cb-6bdcfea82288)

<br>

![image](https://github.com/Digital1O1/4_DOF_Robotic_Arm/assets/39348633/65873aa0-06b8-49ad-9e19-865c6588852b)

<br>

### tail->next = newP

<br>

![image](https://github.com/Digital1O1/4_DOF_Robotic_Arm/assets/39348633/b1948bf9-a8d9-49c4-9eff-c3a47759b7fc)

<br>

### tail = tail -> next

![image](https://github.com/Digital1O1/4_DOF_Robotic_Arm/assets/39348633/0ce3243d-f944-4de6-973b-f85c23245146)

<br>

## Insertion between nodes

```cpp
//https://www.youtube.com/watch?v=UlwpE_4y_A0&ab_channel=NesoAcademy
struct Node *addAfter(struct Node *last, int data, int item)
{
    if (last == NULL)
    return NULL;

    // Travels to target node
    struct Node *temp, *p;

    // Have the p node point towards the first node in the list
    p = last -> next;

    // Searching the item.
    do
    {
        // Found the item
        if (p ->data == item)
        {
            // Creating a node dynamically.
            temp = (struct Node *)malloc(sizeof(struct Node));

            // Assigning the data.
            temp -> data = data;

            // Have the temp pointer point towards the p pointer
            // Have the temp pointer point to the node RIGHT after the one that's being inserted
            temp -> next = p -> next;

            // Move the p pointer towards where the temp/incoming node is at
            p -> next = temp;

            // Checking for the last node.
            if (p == last)
                last = temp;

            return last;
        }
        // Keep moving the pointer forward
        p = p -> next;
    } while (p != last -> next);

    cout << item << " not present in the list." << endl;
    return last;
}
```

<br>

# Deletion in a Circular Linked List

## 1) Delete the node if it's the ONLY node in the circular linked list

-   Free the node's memory
-   Last value should be NULL
-   A node should ALWAYS point towards another
    -   NULL assignment isn't necessary
-   Any node can be set as the starting point
-   Nodes can be traversed quickly from the first to the last

## 2) Deleting the last node

-   Locate the node before reaching the end
    -   We're using a 'temp' node
-   Keep address of the node NEXT to the last node in temp
-   Delete the last memroy
-   Put the temporary node at the end

## 3) Delete any node from the circular linked list

-   The user will give the program a node to be deleted from the current list

```cpp
void deleteNode(Node** head, int key)
{
    // If linked list is empty
    if (*head == NULL)
        return;

    // 1) Delete the node only if it is the only node in the circular linked list:
    // Checks if the 'key' is found AND if the head points towards itself
    if ((*head)->data == key && (*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node *last = *head, *delete_node;

    // If head is to be deleted
    if ((*head)->data == key)
    {
        // Find the last node of the list
        while (last->next != *head)
            last = last->next;

        // Point last node to the next of
        // head i.e. the second node
        // of the list
        last->next = (*head)->next;
        free(*head);
        *head = last->next;
        return;
    }

    // If neither the node to be deleted is found or not at the end of the list keep iterating through
    while (last->next != *head && last->next->data != key)
    {
        last = last->next;
    }

    // If node to be deleted was found
    if (last->next->data == key)
    {
        delete_node = last->next;
        last->next = delete_node->next;
        free(delete_node);
    }
    else
        cout << "Given node is not found in the list!!!\n";
}

```
