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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * larger, * smaller;
        ListNode * largerLast, * smallerLast;
        larger = smaller = largerLast = smallerLast =  NULL;

        ListNode * current = head;
        if (current == NULL)
        {
            return NULL;
        }

        while ( current != NULL)
        {
            if (current->val < x)
            {
                if ( smaller == NULL)
                {
                    smaller = current;
                    smallerLast = current;
                }
                else
                {
                    smallerLast->next = current;
                    smallerLast = current;
                }
            }
            else
            {
                if ( larger == NULL)
                {
                    larger = current;
                    largerLast = current;
                }
                else
                {
                    largerLast->next = current;
                    largerLast = current;
                }
            }
            current = current->next;
        }


        if ( smaller != NULL)
        {
            smallerLast->next = larger;

            if (largerLast != NULL)
            {
                largerLast->next = NULL;
            }
            
            return smaller;

        }
        else
        {
            return larger;
        }
        
    }
};