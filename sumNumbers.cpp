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

    void getSum(TreeNode * root, int sofar, int & total)
    {
        if ( root == NULL)
        {
            return ;
        }

        if ( root->left == NULL && root->right == NULL)
        {
            total += (sofar + root->val);
            return;
        }

        int tmp = (sofar + root->val) * 10;
        if ( root->left != NULL)
        {
            getSum( root->left, tmp, total);
        }

        if ( root->right != NULL)
        {
            getSum( root->right, tmp, total);
        }
    }

    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int total = 0;
        getSum(root, 0, total);
        return total;
    }
};