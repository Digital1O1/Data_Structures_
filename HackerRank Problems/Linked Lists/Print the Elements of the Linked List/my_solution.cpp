#include <iostream>

using namespace std;
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 * Reference link : https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem?isFullScreen=true
 */
class SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
};
void printLinkedList(SinglyLinkedListNode *head)
{

    while (head != NULL)
    {
        std::cout << head->data << std::endl;
        head = head->next;
    }
}

int main()
{
    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count;

    // My stuff

    int number_of_elements = 0;
    int data_values = 0;

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++)
    {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    printLinkedList(llist->head);

    return 0;
}
