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

    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> order;
        stack<TreeNode *> st;
        if (root != NULL)
        {
            TreeNode * tmp = root;
            while (tmp != NULL)
            {
                st.push(tmp);
                tmp = tmp->left;
            }
        }

        while ( !st.empty())
        {
            TreeNode * tmp = st.top(); st.pop();
            order.push_back(tmp->val);
            tmp = tmp->right;
            while (tmp != NULL)
            {
                st.push(tmp);
                tmp = tmp->left;
            }
        }
        return order;
        
    }
};