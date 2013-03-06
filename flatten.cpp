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

    TreeNode * flat(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if ( (root->left == NULL) && (root->right == NULL) )
        {
            return root;
        }

        if ( root->right == NULL)
        {
            root->right = root->left;
            root->left = NULL;
            return flat(root->right);
        }


        if ( root->left == NULL)
        {
            return flat(root->right);
        }

        TreeNode * tmp = flat(root->left); // last node of the left subtree
        tmp->right = root->right; // link the last node's right child to root's right childe
        tmp = flat(root->right);  // flatten the right sub tree and get the last node. 
        root->right = root->left; // set root's right childe (next element in linked list) as root's left child
        root->left = NULL;        // mark left as empty
        return tmp;   // return last element from flat root 's right subtree.
    }

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        flat(root);
    }
};