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
    TreeNode * firstOne;
    TreeNode * secondOne;

    void inOrder(TreeNode * root, TreeNode * &pre)
    {
        if (root->left != NULL)
        {
            inOrder(root->left, pre);
        }

        if ( pre != NULL)
        {
            if ( root->val < pre->val)
            {
                if (firstOne == NULL)
                {
                    firstOne = pre;
                    secondOne = root;
                }
                else
                {
                    secondOne = root;
                }
            }
        }

        pre = root;
        if (root->right != NULL)
        {
            inOrder(root->right, pre);
        }
    }

    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
        {
            return;
        }
        firstOne = NULL;
        secondOne = NULL;
        TreeNode * pre = NULL;
        inOrder(root, pre );

        if (firstOne != NULL && secondOne != NULL)
        {
            int tmp = firstOne->val;
            firstOne->val = secondOne->val;
            secondOne->val = tmp;
        }
    }
};