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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode * > q;

        if (root == NULL)
        {
            return 0;
        }
        
        int depth = 0;
        int counter = 1;
        TreeNode * curr;

        q.push(root);

        while ( ! q.empty() )
        {
            depth++;
            int tmpcounter = 0;
            for (int i = 0; i < counter; i++)
            {
                curr = q.front();
                q.pop();
                if ( curr->left != NULL)
                {
                    q.push(curr->left);
                    tmpcounter++;
                }

                if (curr->right != NULL )
                {
                    q.push(curr->right);
                    tmpcounter++;
                }
            }
            counter = tmpcounter;
        }
        return depth;
    }
};