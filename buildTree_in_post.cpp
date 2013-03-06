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
Recursively:
1. Find the root location, it's easy. The last one of postorder
2. Divide the vector into two sub trees. Carefully rearrange inorder arrary.

*/
class Solution {
public:

    void extracSub(int rootVal, vector<int> &inorder, vector<int> &postorder,
        int leftId, int righId,
        int &leftsubInorder, int &leftsubPosorder,
        int &rightsubInorder,int &rightubPosorder)
    {
        int idx = leftId;
        int size = righId - leftId + 1;
        if ( size < 2)
        {
            return ;
        }

        for (; idx <= righId; idx++)
        {
            if ( inorder[idx] == rootVal )
            {
                break;
            }
        }

        leftsubInorder = leftId;
        leftsubPosorder = idx - 1;
        rightsubInorder = idx;
        rightubPosorder = righId - 1;

        for( ; idx < righId; idx++ )
        {
            inorder[idx]= inorder[idx+1];
        }


    }

    void buildTreeRec(TreeNode * &root, vector<int> &inorder, vector<int> &postorder, int leftId, int rightId)
    {
        int size = rightId - leftId + 1;
        if (size == 1)
        {
            root = new TreeNode(postorder[leftId]);
            return ;
        }

        if ( size == 0 )
        {
            return ;
        }

        int rootId = rightId;
        root = new TreeNode(postorder[rootId]);

        int leftsubInorder;  // this name is confusing, it should be leftsub-left
        int leftsubPosorder; // this name is confusing, it should be leftsub-right
        int rightsubInorder; // this name is confusing, it should be rightsub-left
        int rightubPosorder; // this name is confusing, it should be rightsub-right

        extracSub(root->val, inorder, postorder, leftId, rightId, leftsubInorder, leftsubPosorder, rightsubInorder, rightubPosorder);

        if ( (leftsubPosorder - leftsubInorder + 1) >= 1)
        {
            buildTreeRec(root->left, inorder, postorder, leftsubInorder, leftsubPosorder);
        }

        if ( (rightubPosorder - rightsubInorder + 1) >= 1)
        {
            buildTreeRec(root->right, inorder, postorder, rightsubInorder, rightubPosorder);
        }
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode * root = NULL;
        if (inorder.size() == 0)
        {
            return root;
        }
        int end = inorder.size() - 1;

        buildTreeRec(root, inorder, postorder, 0, end);
        return root;
    }
};