/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *  reverseOneGroup(ListNode *head, int k)
    {
        // assume we have k >= 2
        int counter = 1;
        ListNode * cur = head->next;
        ListNode * pre = head;

        for (int i = 1; i < k; i++)
        {
            ListNode * next;
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = cur;
        return pre;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( k == 1)
        {
            return head;
        }
        if (head == NULL)
        {
            return head;
        }

        ListNode * last = NULL;
        ListNode * reverseHeader = head;
        ListNode * cur = head;
        int counter = 1;
        while ( cur != NULL)
        {
            cur = cur->next;
            if ( (counter % k) == 0 )
            {
                ListNode * newhead = reverseOneGroup(reverseHeader, k);
                if (last == NULL)
                {
                    head = newhead;
                    last = reverseHeader;
                }
                else
                {
                    last->next = newhead;
                    last = reverseHeader;
                }
                reverseHeader = cur;
            }
            counter++;
        }

        return head;
    }
};