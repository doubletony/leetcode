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
    // solve it recursively
    bool isSym(TreeNode * root1, TreeNode * root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }

        if (root1 != NULL && root2 == NULL)
        {
            return false;
        }

        if (root1 == NULL && root2 != NULL)
        {
            return false;
        }

        if (root1->val != root2->val )
        {
            return false;
        }

        if ( ! isSym(root1->left, root2->right)  )
        {
            return false;
        }

        if ( ! isSym(root1->right, root2->left)  )
        {
            return false;
        }

        return true;
    }

    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return isSym(root->left, root->right);
        }
    }
};