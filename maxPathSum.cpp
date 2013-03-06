/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

/*
Trick parts:

1. When the node is NULL, take care of the return value, and notice that don't compare with maxAll
2. The max path is possible that it does not star from the leaf.
3. Deal with a node given it left and right max, there are 4 possible ways to achieve the max value.

*/

class Solution {
public:

    int maxToRootPath(TreeNode * root, int &maxAll)
    {
        if (root == NULL)
        {
            return 0;
        }

        int maxLeft, maxRight;
        maxLeft = maxToRootPath(root->left, maxAll);
        maxRight = maxToRootPath(root->right, maxAll);

        // new way to combine it
        int rootMax = (maxLeft + maxRight + root->val);
        if ( rootMax > maxAll )
        {
            maxAll = rootMax;
        }

        // that's not the right possible to obtain the max value.
        // actually we only have to choose one path from left or right, to return,
        int rootLeftMax = (maxLeft + root->val);
        rootMax = rootLeftMax;
        if ( rootLeftMax > maxAll )
        {
            maxAll = rootLeftMax;
        }

        int rootRightMax = (maxRight + root->val);
        if (rootMax < rootRightMax)
        {
            rootMax = rootRightMax;
        }

        if ( rootRightMax > maxAll )
        {
            maxAll = rootRightMax;
        }

        // check the root itself, to fix the case of
        // {9,6,-3,#,#,-6,2,#,#,2,#,-6,-6,-6}

        if ( rootMax < root->val)
        {
            rootMax = root->val;
        }

        if ( root->val > maxAll )
        {
            maxAll = root->val;
        }
        // return the larger one
        return rootMax;
    }

    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root!=NULL)
        {
            int max_overall = root->val;
            maxToRootPath(root, max_overall);
            return max_overall;
        }
        else
        {
            return 0;
        }
    }
};