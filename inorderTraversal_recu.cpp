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
    void inorder(TreeNode *root, vector<int> &order)
    {
        if (root == NULL)
        {
            return ;
        }
        if (root->left != NULL)
        {
            inorder(root->left, order);
        }
        
        order.push_back(root->val);

        if (root->right != NULL)
        {
            inorder(root->right, order);
        }
    }

    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> order;
        inorder(root, order);
        return order;
        
    }
};