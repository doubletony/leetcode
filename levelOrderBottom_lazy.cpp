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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode *> q;
        vector<vector<int> > rslt;

        int count = 0;
        if (root != NULL)
        {
            q.push(root);
            count = 1;
        }

        while( ! q.empty() )
        {
            vector<int> level;
            int newCount = 0;
            for (int i = 0; i < count; i++)
            {
                TreeNode * node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != NULL)
                {
                    q.push(node->left);
                    newCount++;
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                    newCount++;
                }
            }
            rslt.push_back(level);
            count = newCount;
        }
        return rslt;
    }

    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > rslt = levelOrder(root);
        reverse(rslt.begin(), rslt.end() );
        return rslt;
    }
};