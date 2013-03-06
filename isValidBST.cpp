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
    bool isValidBSTi(TreeNode *root, int &pre) 
    {
        if (root == NULL)
        {
            return true;
        }

        if ( root->left != NULL)
        {
            if ( ! isValidBSTi(root->left, pre) )
                return false;
        }

        if ( root->val <= pre)
        {
            return false;
        }

        pre = root->val;


        if ( root->right != NULL)
        {
            if ( ! isValidBSTi(root->right, pre) )
                return false;
        }
        return true;
        
    }

    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
        {
            return true;
        }
        int pre = INT_MIN;

        return isValidBSTi(root, pre);
    }
};