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
    TreeNode * buildUp(vector<int> &num, int start, int end)
    {
        if ( end < start)
        {
            return NULL;
        }

        if ( end == start)
        {
            TreeNode * root = new TreeNode(num[end]);
            return root;
        }

        if ( (end - start) == 1)
        {
            TreeNode * root = new TreeNode(num[end]);
            TreeNode * leftChild = new TreeNode(num[start]);
            root->left = leftChild;
            return root;
        }

        int mid = (start + end) / 2;
        TreeNode * root = new TreeNode(num[mid]);
        root->left = buildUp(num, start, mid - 1);
        root->right = buildUp(num, mid+1, end);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        return buildUp(num, 0, num.size() - 1);
    }
};