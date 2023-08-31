#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedLists
{
private:
    Node *head, *previous, *tail, *next_, *current;

public:
    LinkedLists()
    {
        head = NULL;
        tail = NULL;
        previous = NULL;
        next_ = NULL;
    }
    void addNode(int value)
    {
        Node *temp = new Node();
        temp->next = head;
        temp->data = value;
        head = temp;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            // cout << temp->data << " ";
            temp = temp->next;
        }
        printf("\n");
    }

    void reverseNodes()
    {
        /*
            Advance next node forward
            Move current node to forward node
            Reverse forward node to previous node
        */
        current = head;
        while (current != NULL)
        {
            // move 'next' to the next link
            next_ = current->next;
            // reverses link
            current->next = previous;
            // Move pointers one position ahead.
            previous = current;
            // Move current to where next is at
            current = next_;
        }
        head = previous;
    }

    void deleteNodeAtGivenValue(int targetValue)
    {
        printf("Deleting the value : %d \r\n", targetValue);

        // Check if the list isn't empty
        if (head != NULL)
        {
            // list is not empty
            // need to traverse list, stopping at the last node
            // Node *currNode = head;
            current = head;

            // If second node needs to be deleted
            if (head->data == targetValue)
            {
                // 'Jump' over the node
                head = head->next;
                delete current;
            }
            else
            { // case 3... the node to delete is not the first node, but might not even be in the list
                // Node *prevNode = NULL;
                previous = NULL;
                while (current != NULL && current->data != targetValue)
                {
                    //  prevNode
                    previous = current;

                    // Move currNode 'forward'
                    current = current->next;
                }
                // check if we found targetValue
                if (current != NULL)
                {
                    // Skip over currNode
                    previous->next = current->next;
                    delete current;
                }
            }
        }
    }

    void getNthNode(uint8_t position)
    {
        uint8_t count = 0;
        Node *temp = new Node();
        temp = head;

        while (temp != NULL && count != position)
        {
            temp = temp->next;
            count++;
        }
        printf("The node at position [ %d ] is : [ %d ] \r\n", position, temp->data);
    }
};

int main()
{
    LinkedLists ll;

    ll.addNode(5);
    ll.addNode(44);
    ll.addNode(3);
    ll.addNode(11);

    printf("Original linked list\r\n");
    ll.print();

    ll.getNthNode(2);

    return 0;
}