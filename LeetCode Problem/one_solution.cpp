class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {

        int result = head->val;
        while (head->next)
        {
            result = result * 2 + head->next->val;
            head = head->next;

            /*
                result 0 val 0 --> 0 x 2 + 0 --> 0
                result 0 val 1 --> 1 x 2 + 0 --> 1
                result 1 val 1 --> 1 x 2 + 0 --> 1
                result 0 val 1 --> 1 x 2 + 0 --> 1


            */
        }
        return result;
    }
};
