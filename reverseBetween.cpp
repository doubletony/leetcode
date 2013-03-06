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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * pre, * next;
        ListNode * start, * end;
        pre = next = NULL;
        int counter = 1;
        ListNode * cur = head;
        ListNode * precur = NULL;

        while ( cur != NULL)
        {
            if ( counter == (m-1) )
            {
                pre = cur;
            }

            if ( counter == (n+1) )
            {
                next = cur;
            }

            if ( counter == m )
            {
                start = cur;
            }

            if ( counter == n )
            {
                end = cur;
            }

            if ( counter > m && counter <= n )
            {
                ListNode * nextCur;
                nextCur = cur->next;
                cur->next = precur;
                precur = cur;
                cur = nextCur;
            }
            else
            {
                precur = cur;
                cur = cur->next;
            }
            counter++;
        }

        if (pre == NULL)
        {
            head = end;
        }
        else
        {
            pre->next = end;
        }
        
        start->next = next;

        return head;
    }
};