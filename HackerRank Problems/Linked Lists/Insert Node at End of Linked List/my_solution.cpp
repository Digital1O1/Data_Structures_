#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;

    SinglyLinkedList()
    {
        this->head = nullptr;
    }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep, ofstream &fout)
{
    while (node)
    {
        fout << node->data;

        node = node->next;

        if (node)
        {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode *node)
{
    while (node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode *insertNodeAtTail(SinglyLinkedListNode *head, int data)
{
    /*
        Given pointer to head node of linked list and a integer to add to the list
        Make new node with given integer
        Add this particular node at endo f linked list
        Return head node of linked list after inserting new node
        Given head pointer may be null
            - Indicates initial list is empty

        n = 5 = sample size

        TL;DR every input is placed at the end of the linked list since the first element is NULL
            - First element : 141   --> 141 -> NULL.
            - Second element : 302  -->  141 -> 302 -> NULL
            - Third element : 164   -->  141 -> 302 -> 164 -> NULL.
            - Fourth element : 530  --> 141 -> 302 -> 164 -> 530 -> NULL
            - Fifth element : 474   --> 141 -> 302 -> 164 -> 530 -> 474 -> NULL
    */

    while (head != NULL)
    {
        std::cout << head->data << std::endl;
        head = head->next;
    }
    return head;
}

int main()
{
    cout << "PROGRAM STARTED" << endl;
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count = 5;
    // cin >> llist_count;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int llist_item[] = {141, 302, 164, 530, 474};
    for (int i = 0; i < llist_count; i++)
    {
        // int llist_item;
        // cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        SinglyLinkedListNode *llist_head = insertNodeAtTail(llist->head, llist_item[i]);
        llist->head = llist_head;
    }

    print_singly_linked_list(llist->head, "\n", fout);
    fout << "\n";

    free_singly_linked_list(llist->head);

    fout.close();

    return 0;
}
