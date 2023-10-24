/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *previous = NULL;
        ListNode *next = NULL;

        while (current != NULL)
        {
            // printf("%d ",current->val);
            // current = current->next;

            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        head = previous;

        return head;
    }
};