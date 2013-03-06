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
    void setHeight(TreeNode *root, bool &balanced)
    {
        if (root == NULL)
        {
            return ;
        }

        if ( (root->left == NULL) && (root->right == NULL) )
        {
            root->val = 1; // or zero
            return ;
        }

        if ( !balanced )
        {
            return ;
        }

        if (root->left != NULL) setHeight(root->left, balanced);
        if (root->right != NULL) setHeight(root->right, balanced);

        int lefth,righth;
        if (root->left == NULL)
        {
            lefth = 0;
            righth = root->right->val;
            root->val = root->right->val + 1;
        }
        else if (root->right == NULL)
        {
            righth = 0;
            lefth = root->left->val;
            root->val = root->left->val + 1;
        }
        else
        {
            lefth = root->left->val;
            righth = root->right->val;
            root->val = (lefth > righth ) ? (lefth + 1) : (righth + 1);
        }

        if ( abs(lefth - righth) > 1 )
        {
            balanced = false;
        }
    }

    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool isBal = true;
        setHeight(root, isBal);
        return isBal;

    }
};