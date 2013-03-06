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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
        {
            return NULL;
        }

        ListNode * cur = head;
        ListNode * newhead = NULL;
        ListNode * last = NULL;
        bool removeMe = false;
        bool findNew = false;
        while ( cur != NULL)
        {
            if (cur->next == NULL)
            {
                if (removeMe)
                {
                    if (last != NULL)
                    {
                        last->next = cur->next;
                        removeMe = false;
                    }
                }
                else
                {
                    if (last != NULL)
                    {
                        last->next = cur;
                    }
                    last = cur;
                    if (!findNew)
                    {
                        newhead = cur;
                        findNew = true;
                        removeMe = false;
                    }
                }
                cur = cur->next;
                continue;
            }

            if (cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
                removeMe = true;
            }
            else
            {
                if (removeMe)
                {
                    if (last != NULL)
                    {
                        last->next = cur->next;
                        removeMe = false;
                    }
                }
                else
                {
                    if (last != NULL)
                    {
                        last->next = cur;
                    }
                    last = cur;
                    if (!findNew)
                    {
                        newhead = cur;
                        findNew = true;
                        removeMe = false;
                    }
                }
                cur = cur->next;
            }
        }

        return newhead;
    }
};