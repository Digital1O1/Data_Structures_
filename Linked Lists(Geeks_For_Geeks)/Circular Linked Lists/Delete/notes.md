# Deleting first node from Singly Circular Linked Lists

## Diagram 

![image](https://github.com/Digital1O1/Current_VIMRC/assets/39348633/4b025f6d-4b21-46c9-aba9-725a0836505a)


## Approach 
1) Take two pointers and have both traverse the list
    - Current 
    - Previous 
2) Keep the pointer `current` fixed on pointing to the first node
   - Move the `previous` node until it reaches the last node
3) Once the `previous` pointer reaches the last node it does the following:
   
   ```c++
   previous->next = current->next
   head = previous->next
   ```
## Code example

```cpp
// Function to delete First node of
// Circular Linked List
void DeleteFirst(struct Node** head)
{
    //struct Node *previous = *head, *firstNode = *head;
    Node *head = new Node();
    Node *firstNode = new Node();
    Node *head = new Node();

    // check if list doesn't have any node
    // if not then return
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }
 
    // check if list have single node
    // if yes then delete it and return
    if (previous->next == previous) {
        *head = NULL;
        return;
    }
 
    // traverse second node to first
    while (previous->next != *head) 
    {
        previous = previous->next;
    }
 
    // now previous is last node and
    // first node(firstNode) link address
    // put in last node(previous) link
    previous->next = firstNode->next;
 
    // make second node as head node
    *head = previous->next;
    free(firstNode);
    return;
}

void DeleteFirst2(Node** tail)
{
    if (head == nullptr) 
    {
        std::cout << "List is empty. Cannot delete." << std::endl;
        return;
    }

    if (head->next == head) 
    {
        // If there's only one node in the list, delete it and set head to nullptr
        delete head;
        head = nullptr;
    } 
    else 
    {
        // Find the last node to update its next pointer
        Node* last_node = head;
        while (last_node->next != head) 
        {
            last_node = last_node->next;
        }

        // Update the last node's next pointer to skip the first node
        // This will point towards the second node in the list
        last_node->next = head->next;

        // Save a reference to the current head, move head to the next node, and delete the old head
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

```