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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * returnHead = NULL;

        if (head == NULL)
        {
            return NULL;
        }

        if (head->next == NULL)
        {
            return head;
        }

        if ( head->next != NULL)
        {
            returnHead = head->next;
        }

        ListNode * cur, * pre;
        pre = NULL;
        cur=head;
        while ( cur != NULL && cur->next != NULL)
        {
            ListNode * nextCur;
            nextCur = cur->next->next;

            // swap cur and its next;

            ListNode * next;
            next = cur->next;

            next->next = cur;
            if ( pre != NULL)
            {
                pre->next = next;
            }

            pre = cur;
            cur = nextCur;
        }

        if (cur != NULL)
        {
            pre->next = cur;
        }
        else
        {
            pre->next = NULL;
        }
        return returnHead;
    }
};