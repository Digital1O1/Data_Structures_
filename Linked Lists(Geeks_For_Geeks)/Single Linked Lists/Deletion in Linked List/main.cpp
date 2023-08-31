// Reference link : https://www.geeksforgeeks.org/deletion-in-linked-list/?ref=lbp
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int new_data)
{
    /* 1. allocate node */
    Node *new_node = new Node();

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void delete_node_at_pos(Node **head, int position)
{

    // Points to the node RIGHT before the one we're going to delete
    Node *previous = *head;

    // This node will point to whatever we want to delete
    Node *current = *head;

    // Check if LL is empty
    if (*head == NULL)
    {
        printf("Linked List is EMPTY \r\n");
    }

    // If the user wants to delete the first node of the list
    else if (position == 1)
    {
        // Move head pointer to next node in list
        *head = current->next;

        // Delete the node in the first position
        free(current);

        // This has to be done or you'll lose the link and the entire linked list
        current = NULL;
    }
    else
    {
        // This will iterate through the linked list
        while (position != 1)
        {
            // move current pointer to where previous pointer is at
            previous = current;

            // move the pointer to the next node
            current = current->next;
            position--;
        }
        // When position == 1, delete that node

        // This will take the previous node and point 'over' the node that's about to get deleted
        previous->next = current->next;

        free(current);
        current = NULL;
    }

    /*
        If there were three nodes, node A/B/C

        If we wanted to update the previous node to point to the node AFTER the one we're about to delete,
        it would look something like this

        previous->next = current->next
    */
}

void delete_at_end(Node **head)
{
    Node *second_last = *head;

    // If list is already empty
    if (head == NULL)
        printf("LIST IS EMPTY\r\n");
    // return NULL;

    if (second_last->next == NULL)
    {
        delete head;
        // return NULL;
    }

    // Keeo looping until you hit NULL
    while (second_last->next)
        second_last = second_last->next;

    // Delete last node
    delete (second_last->next);

    // Change next of second last
    second_last->next = NULL;
}
int main()
{
    /* Start with the empty list */
    Node *head = NULL;

    push(&head, 1);
    push(&head, 3);
    push(&head, 4);
    push(&head, 6);

    printList(head);

    delete_node_at_pos(&head, 2);

    printList(head);
    cout << endl;
    delete_at_end(&head);
    printList(head);

    return 0;
}