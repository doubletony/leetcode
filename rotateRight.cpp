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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( head == NULL)
        {
            return head;
        }
        
        if ( k == 0)
        {
            return head;
        }

        ListNode * cur = head;
        int total = 1;
        while ( cur->next != NULL)
        {
            cur = cur->next;
            total++;
        }

        cur->next = head;
        ListNode * pre = cur;
        int counter = 1;
        cur = head;
        k = (k % total);
        k = total - k;

        while ( counter <= k )
        {
            pre = cur;
            cur = cur->next;
            counter++;
        }


        // break it
        head = pre->next;
        pre->next = NULL;
        return head;
    }
};