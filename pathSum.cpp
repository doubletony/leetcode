
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > rslt;
        vector<vector<int> > left;
        vector<vector<int> > right;

        if (root == NULL)
        {
            return rslt;
        }

        // check leaf

        if ( root->left == NULL && root->right == NULL)
        {
            //
            if (root->val == sum)
            {
                vector<int> tmp;
                tmp.push_back(root->val);
                rslt.push_back(tmp);
            }

            return rslt;
        }

        if ( root->left != NULL)
        {
            left = pathSum(root->left, sum - root->val);
        }

        if ( root->right != NULL)
        {
            right = pathSum(root->right, sum - root->val);
        }

        // merge
        for (int i = 0; i < left.size(); i++)
        {
            vector<int> tmp;
            tmp.push_back(root->val);
            for (int j = 0; j < left[i].size(); j++)
            {
                tmp.push_back(left[i][j]);
            }
            rslt.push_back(tmp);
        }

        for (int i = 0; i < right.size(); i++)
        {
            vector<int> tmp;
            tmp.push_back(root->val);
            for (int j = 0; j < right[i].size(); j++)
            {
                tmp.push_back(right[i][j]);
            }
            rslt.push_back(tmp);
        }
        return rslt;

    }
};