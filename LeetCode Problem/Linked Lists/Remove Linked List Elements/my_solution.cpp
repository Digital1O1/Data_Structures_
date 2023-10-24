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
    ListNode *removeElements(ListNode *head, int key)
    {
        ListNode *temp = head;
        ListNode *deleteIt = NULL;

        while (temp != NULL)
        {
            printf("%d ", temp->val);

            if (temp->val == key)
            {
                // printf("VALUE FOUND %d \r\n",temp->val);
                // ListNode *deleteIt = temp;
                temp->next = temp->next;

                printf("\ndeleteIt : %d \r\n", deleteIt->val);
                // temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }

            // printf("%d ",temp->val);
            // temp = temp->next;
            //  Run time error if left here
            //  if(temp->val == key)
            //  {
            //      printf("VALUE FOUND %d \r\n",temp->val);
            //  }
        }
        // This wont work since the while loop cause the LL to go to NULL, hence the error
        // printf("\ndeleteIT : %d \r\n",deleteIt->val);

        return head;
    }
};