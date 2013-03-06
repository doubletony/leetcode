/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode * buildUpEmpty(int num)
    {
        if ( num  <= 0)
        {
            return NULL;
        }

        if ( num == 1)
        {
            TreeNode * root = new TreeNode(-1);
            return root;
        }
        
        if ( num == 2)
        {
            TreeNode * root = new TreeNode(-1);
            TreeNode * left = new TreeNode(-1);
            root->left = left;
            return root;
        }

        int lefthalf = num / 2;
        int rightHalf = (num + 1) / 2;
        TreeNode * root = new TreeNode(-1);
        root->left =  buildUpEmpty(lefthalf);
        root->right =  buildUpEmpty(rightHalf - 1);
        return root;
    }

    void fillTreeInorder(ListNode * &lNode, TreeNode * tNode)
    {
        if (tNode == NULL)
        {
            return ;
        }

        fillTreeInorder( lNode, tNode->left);
        tNode->val = lNode->val;
        lNode = lNode->next;
        fillTreeInorder( lNode, tNode->right);
    }

    int listSize(ListNode * head)
    {
        int count = 0;
        ListNode * node = head;
        while ( node != NULL )
        {
            node = node->next;
            count++;
        }
        return count;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = listSize(head);
        if (size == 0)
        {
            return NULL;
        }
        
        TreeNode * root = buildUpEmpty(size);

        fillTreeInorder(head, root);
        return root;
    }
};