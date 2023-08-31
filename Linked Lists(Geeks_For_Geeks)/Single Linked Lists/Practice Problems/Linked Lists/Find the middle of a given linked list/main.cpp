#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head, *previous, *tail, *next_, *current;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        previous = NULL;
        next_ = NULL;
    }
    void addNode(uint8_t incoming_data)
    {
        Node *temp = new Node();
        temp->next = head;
        temp->data = incoming_data;
        head = temp;
    }
    void printlist()
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
    void findMiddleNode()
    {
        Node *fast = head;
        Node *slow = head;

        if(head!=NULL)
        {
            // while(fast != NULL && slow != NULL)
            while (fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            printf("Middle element : %d \r\n", slow->data);
        }

    }
};
int main()
{
    LinkedList ll;

    ll.addNode(1);
    ll.addNode(3);
    ll.addNode(7);
    ll.addNode(6);
    ll.addNode(7);
    ll.addNode(9);
    ll.addNode(10);

    ll.printlist();
    //  10 9 7 6 7 3 1
    ll.findMiddleNode();
    return 0;
}