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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( (l1 == NULL) && (l2 == NULL) )
        {
            return NULL;
        }
        else if (l1 == NULL)
        {
            return l2; // not good
        }
        else if (l2 == NULL)
        {
            return l1; // also not good
        }

        int carry = 0;
        ListNode * rst = new ListNode(0);
        ListNode * iter = rst;
        for ( ; (l1 != NULL) || (l2 != NULL); )
        {   
            int ca, cb;
            ca = cb = 0;

            if (l1 != NULL) ca = l1->val;
            if (l2 != NULL) cb = l2->val;
            
            iter->val = (ca + cb + carry) % 10;
            carry = (ca + cb + carry) / 10;
            iter->next = new ListNode(0);

            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
            if ((l1 != NULL) || (l2 != NULL)) iter = iter->next;
        }
        
        if ( carry > 0)
        {
            iter->next->val = carry;
        }
        else
        {
            delete iter->next;
            iter->next = NULL;
        }

        return rst;
    }
};