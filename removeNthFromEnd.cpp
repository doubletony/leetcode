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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * cur;
        ListNode * tar;
        ListNode * pre = NULL;

        cur = head;
        int counter = 1;
        while ( cur != NULL)
        {
            if (counter < n)
            {
                counter++;
                cur = cur->next;
            }
            else if (counter == n)
            {
                tar = head;
                cur = cur->next;
                counter++;
            }
            else
            {
                pre = tar;
                tar = tar->next;
                cur = cur->next;
            }
        }

        if (pre == NULL)
        {
            head = tar->next;
        }
        else
        {
            pre->next = tar->next;
        }

        return head;
    }
};