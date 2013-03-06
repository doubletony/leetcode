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
    bool sameNode(TreeNode *p, TreeNode *q)
    {
        if ( (p == NULL) && (q == NULL) )
        {
            return true;
        }

        if ( (p == NULL) && (q != NULL) )
        {
            return false;
        }

        if ( (q == NULL) && (p != NULL) )
        {
            return false;
        }

        if ( q->val != p->val)
        {
            return false;
        }

        return true;
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( (p == NULL) && (q == NULL) )
        {
            return true;
        }

        if ( (p == NULL) && (q != NULL) )
        {
            return false;
        }

        if ( (q == NULL) && (p != NULL) )
        {
            return false;
        }

        if ( q->val != p->val)
        {
            return false;
        }

        if ( isSameTree(p->left, q->left) && isSameTree(p->right, q->right) )
        {
            return true;
        }

        return false;
    }
};