# [Deleting first node from Singly Circular Linked Lists](https://www.geeksforgeeks.org/deletion-at-different-positions-in-a-circular-linked-list/#)

## Diagram

![image](https://github.com/Digital1O1/Current_VIMRC/assets/39348633/4b025f6d-4b21-46c9-aba9-725a0836505a)

## Approach

1. Take two pointers and have both traverse the list
   - Current
   - Previous
2. Keep the pointer `current` fixed on pointing to the first node
   - Move the `previous` node until it reaches the last node
3. Once the `previous` pointer reaches the last node it does the following:

   ```c++
   // Have the previous pointer point to the second node
   // This node will be the new 'front'
   previous->next = current->next

   // Update the head pointer
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

    // Traverses to the first node of the linked list
    while (previous->next != *head)
    {
        // Have previous point to the 2nd node in list
        previous = previous->next;
    }

    // now previous is last node and
    // first node(firstNode) link address
    // put in last node(previous) link

    // This line pretty much 'detaches' the first node from the list and makes the second node the new head of the list
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

# Deleting nodes at given index in the Circular linked list

## Approach

- Determine number of nodes in the list
- Take two pointers, `previous` and `current` to traverse the list
  - Ensure the `previous` node is behind the `current` node
- Initialize `count` variable to 0 to keep track of number of nodes traversed
- Traverse lsit until given index is reached
  - Once index is reached, do `previous->next = current->next`

```cpp
// Function to delete node at given index
// of Circular Linked List
void DeleteAtPosition(Node* head, int index)
{
	// find length of list
	int len = Length(head);
	int count = 1;
	Node* previous = head;
	Node* next = head;

	// check if list doesn't have any node
	// if not then return
	if(head == NULL)
    {
		cout<<"Delete Last list is empty";
		return;
	}

	// given index is in list or not
	if(index >= len || index<0)
    {
		cout<<"Index is not Found";
		return;
	}

	// delete first node
	if(index == 0)
    {
		DeleteFirst(head);
		return;
	}

	// traverse first to last node
	while(len > 0)
    {
		// if index found delete that node
		if(index == count)
        {
			previous->next = next->next;
			free(next);
			return;
		}
		previous = previous->next;
		next = previous->next;
		len--;
		count++;
	}
	return;
}

Or....

void DeleteAtPosition(Node*& head, int index)
{
    // Error checker

    if (head == nullptr) {
        throw std::runtime_error("List is empty. Deletion not possible");
    }

    if (index < 0) {
        throw std::out_of_range("Index is not valid");
    }

    // Delete node if at front
    if (index == 0) {
        DeleteFirst(head);
        return;
    }

    Node* previous = head;
    Node* current = head->next;
    int count = 1;

    /*
        Iterate through list until
            - You hit the nullptr
            - And if the 'index' variable is greater than the lenght of the list, aka the 'count'
    */
    while (current != nullptr && count < index)
    {
        // Update previous to where current is at
        previous = current;

        // Advance current
        current = current->next;

        // Update count iterator
        count++;
    }

    if (current == nullptr) {
        throw std::out_of_range("Index is out of bounds");
    }

    previous->next = current->next;
    delete current;
}

```
