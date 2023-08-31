#include <iostream>

class Node
{
public:
    int data;
    Node *next;
};

using namespace std;

void add_node(Node **head, int value)
{
    // Moved the temp pointer to the head pointer
    // Node *temp = *head;

    // This was right
    // temp->data = value;

    // Thought I needed to move the node forward for some reason
    // temp = temp->next;

    // This was right
    // *head = temp;

    // Allocate space for new node
    Node *new_node = new Node();

    // Insert new data into node
    new_node->data = value;

    // Make new node point towards head
    new_node->next = (*head);

    // 'Move' the new node
    (*head) = new_node;
}

// void delete_node_at_position(Node **head, int position)
// {
//     Node *temp = *head;
//     for (int i = 0; i <= position; i++)
//     {
//         temp = temp->next;
//     }
//     printf("%d ", temp->data);
//     // while (temp->next && position !=0)
//     // {
//     //     printf("%d ", temp->data);
//     //     temp = temp->next;
//     // }
//     // while (temp->next && position != 0)
//     // {

//     //     temp = temp->next;
//     //     position--;
//     // }
//     // printf("Node to be deleted : %d \r\n", temp->data);
// }

void delete_node_at_position2(Node **head, int position)
{
    // https://www.youtube.com/watch?v=f1r_jxCyOl0&t=3s&ab_channel=NesoAcademy
    Node *current = *head;
    Node *previous = *head;

    // If list is empty 
    if (*head == NULL)
    {
        printf("LIST EMPTY\r\n");
    }

    // If the deleted node is at the front of the list
    else if (position == 1)
    {
        *head = current->next;
        free(current);
        // 'Save' the pointer
        current = NULL;
    }

    // If not, iterate through the list
    else
    {
        while (position != 1)
        {
            // update links
            previous = current;

            // move current link forward
            current = current->next;

            // Decrement position value
            position--;
        }
        printf("Deleting the following link : %d \r\n", current->data);

        // Have previous pointer 'jump' one ahead of the current pointer
        previous->next = current->next;

        // Delete the current pointer
        free(current);

        // Have the current pointer point to NULL
        current = NULL;
    }
}
void delete_node_at_position(Node **head, int position)
{
    // Reference link : https://www.youtube.com/watch?v=BrjLWNuJ3HA&ab_channel=GeeksforGeeks
    // If linked list is empty
    if (*head == NULL)
        return;

    // Store head node
    Node *temp = *head;

    // If head needs to be removed
    if (position == 0)
    {
        // Change head
        *head = temp->next;

        // Free old head
        free(temp);
        return;
    }

    // Find previous node of the node to be deleted
    // 1 10 15 --> 1 [10] 15 --> 10 is what's to be 'saved'
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node *next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next); // Free memory

    // Unlink the deleted node from list
    temp->next = next;
}
void printList(Node *head)
{
    // while (head->next)
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\r\n");
}

int main()
{
    Node *head = NULL;
    add_node(&head, 1);
    add_node(&head, 10);
    add_node(&head, 15);
    add_node(&head, 25);
    add_node(&head, 122);

    printList(head);
    // delete_node_at_position(&head, 1);
    // Furthest right value --> 0th index
    delete_node_at_position2(&head, 2);

    // delete_node_at_position(&head, 2);
    printList(head);
    return 0;
}