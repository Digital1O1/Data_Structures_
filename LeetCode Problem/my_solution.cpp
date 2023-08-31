// 1290. Convert Binary Number in a Linked List to Integer
// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
    int getDecimalValue(ListNode *head)
    {
        int storage_array[31] = {0};
        int count = 0;
        int total = 0;
        ListNode *incoming_node = head;
        while (incoming_node != NULL)
        {
            // printf("%d ",incoming_node->val);
            if (incoming_node->val >= 1)
            {
                storage_array[count] = 1;
            }
            else
            {
                storage_array[count] = 0;
            }
            count++;
            incoming_node = incoming_node->next;
        }

        for (int i = 0; i < sizeof(storage_array) / sizeof(storage_array[0]); i++)
        {
            printf("%d ", storage_array[i]);
        }

        return 0;
    }
};