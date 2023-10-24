// C++ program to delete node at different
// positions from a circular linked list
#include <iostream>
using namespace std;

// structure for a node
class Node
{
public:
    int data;
    Node *next;
};

// Function to insert a node at the end of
// a Circular linked list
void Insert(Node **head, int data)
{
    // Create a pointer 'current' and initialize it with the head node
    Node *current = *head;

    // Create a new node and allocate memory for it
    Node *newNode = new Node;

    // Check if memory allocation for the new node was successful
    if (!newNode)
    {
        printf("\nMemory Error\n");
        return;
    }

    // Insert the data into the newly created node
    newNode->data = data;

    // Check if the list is empty
    if (*head == NULL)
    {
        // If the list is empty, make the new node point to itself
        newNode->next = newNode;

        // Update the head pointer to point to the new (and only) node in the list
        *head = newNode;

        return; // The insertion is complete
    }
    else
    {
        // If the list is NOT empty, we need to find the last node
        // We start from the head node and traverse until we reach the last node
        while (current->next != *head)
        {
            current = current->next;
        }

        // At this point, 'current' points to the LAST node in the list

        // The 'newNode' currently isn't pointing towards anything
        // Make the new node point to the head, creating a circular link
        // Think of the following line like this : newNode --> *head
        newNode->next = *head;

        // Update the current 'next' pointer of the last node to point to the new node
        current->next = newNode;
    }
}

// Function print data of list
void Display(Node *head)
{
    struct Node *current = head;

    // if list is empty, simply show message
    if (head == NULL)
    {
        printf("\nDisplay List is empty\n");
        return;
    }

    // traverse first to last node
    else
    {
        do
        {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    }
}

// Function return number of nodes present in list
int Length(Node *head)
{
    Node *current = head;
    int count = 0;

    // if list is empty simply return length zero
    if (head == NULL)
    {
        return 0;
    }

    // traverse first to last node
    else
    {
        do
        {
            current = current->next;
            count++;
        } while (current != head);
    }
    return count;
}

// Function delete First node of Circular Linked List
void DeleteFirst(Node **head)
{
    Node *previous = *head;
    Node *node_delete = *head;

    // Check if the list is empty
    if (*head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    // Check if the list contains a single node
    if (previous->next == previous)
    {
        *head = NULL; // The list becomes empty
        free(previous);
        return;
    }

    // Traverse to find the last node
    while (previous->next != *head)
    {
        // Update the previous node
        // previous = next;

        // Do the actual traversing
        previous = previous->next;
    }

    // Now 'previous' is the LAST node, and 'node_delete' is the FIRST node

    // Update the last node's next pointer to skip the first node
    previous->next = node_delete->next;

    // Make the second node (next) the new head of the list
    *head = previous->next;

    // Free the memory of the old first node
    free(node_delete);

    return;
}

// Function to delete last node of
// Circular Linked List
void DeleteLast(Node **head)
{
    Node *current = *head, *previous = NULL;

    // Check if the list is empty
    if (*head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    // Check if the list has only one node
    if (current->next == *head)
    {
        *head = NULL;
        free(current);
        return;
    }

    // Traverse the list to find the second-to-last node
    while (current->next != *head)
    {
        // Store the current node as the previous node
        previous = current;

        // Move current to the next node
        current = current->next;
    }

    // Update the previous node's next pointer to skip the last node
    previous->next = *head;

    // Free the last node to deallocate memory
    free(current);
}

void DeleteNodeAtPosition(Node **head, int position)
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        std::cout << "List is empty. Deletion not possible." << std::endl;
        return;
    }

    Node *current = *head;    // Create a pointer to the current node, starting from the head
    Node *previous = nullptr; // Create a pointer to the previous node, initially nullptr

    int count = 0; // Initialize a counter to keep track of the position

    // Traverse the list to find the node at the specified position
    while (count < position)
    {
        previous = current;      // Store the current node as the previous node
        current = current->next; // Move to the next node
        count++;

        // Check if we have cycled back to the head of the list while we're still traversing the list
        if (current == *head)
        {
            std::cout << "Position " << position << " is out of bounds." << std::endl;
            return;
        }
    }

    // The following if statement checks if we're back at the start of the list
    // Remove the node at the specified position, which in this case is the head pointer
    if (current == *head)
    {
        // If we are deleting the head node, update the head
        // Temp is used to traverse the list
        Node *temp = *head;

        // Iterate until we get to the head node
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = (*head)->next; // Update the last node's next pointer Update the temp node
                                    // Update temp's pointer to bypass the head's pointer to maintain the circular structure

        *head = (*head)->next; // Updated to point to the new head node
    }
    else
    {
        // If we are deleting a node other than the head
        // Remember we used the current node to traverse to where we need to be
        // So in this case, we're having the previous pointer point ahead of where the current pointer is currently at to ensure the links are still emplaced
        previous->next = current->next;
    }

    delete current; // Delete the node at the specified position
}

// Driver Code
int main()
{
    struct Node *head = NULL;
    Insert(&head, 99);
    Insert(&head, 11);
    Insert(&head, 22);
    Insert(&head, 33);
    Insert(&head, 44);
    Insert(&head, 55);
    Insert(&head, 66);

    // // Deleting Node at position
    // printf("Initial List: ");
    // Display(head);
    // printf("\nAfter Deleting node at index 4: ");
    // DeleteAtPosition(&head, 4);
    // Display(head);

    // // Deleting first Node
    // printf("\n\nInitial List: ");
    // Display(head);
    // printf("\nAfter Deleting first node: ");
    // DeleteFirst(&head);
    // Display(head);

    // Deleting last Node
    printf("\n\nInitial List: ");
    Display(head);
    printf("\nAfter Deleting last node: ");
    DeleteLast(&head);
    Display(head);

    return 0;
}
