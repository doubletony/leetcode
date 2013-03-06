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
Similar to build tree from inorder and post order The difference is that now
the root is the first in preorder, and we should rearrange inorder arrary in
opposite manner.

Recursively:
1. Find the root location, it's easy. The last one of postorder
2. Divide the vector into two sub trees. Carefully rearrange inorder arrary.

*/
class Solution {
public:

    void extracSub(int rootVal, vector<int> &inorder, vector<int> &preorder,
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

        leftsubInorder = leftId + 1;
        leftsubPosorder = idx;
        rightsubInorder = idx + 1;
        rightubPosorder = righId;

        for( ; idx > leftId; idx-- )
        {
            inorder[idx]= inorder[idx-1];
        }


    }

    void buildTreeRec(TreeNode * &root, vector<int> &inorder, vector<int> &preorder, int leftId, int rightId)
    {
        int size = rightId - leftId + 1;
        if (size == 1)
        {
            root = new TreeNode(preorder[leftId]);
            return ;
        }

        if ( size == 0 )
        {
            return ;
        }

        int rootId = rightId;
        root = new TreeNode(preorder[leftId]);

        int leftsubInorder;  // this name is confusing, it should be leftsub-left
        int leftsubPosorder; // this name is confusing, it should be leftsub-right
        int rightsubInorder; // this name is confusing, it should be rightsub-left
        int rightubPosorder; // this name is confusing, it should be rightsub-right

        extracSub(root->val, inorder, preorder, leftId, rightId, leftsubInorder, leftsubPosorder, rightsubInorder, rightubPosorder);

        if ( (leftsubPosorder - leftsubInorder + 1) >= 1)
        {
            buildTreeRec(root->left, inorder, preorder, leftsubInorder, leftsubPosorder);
        }

        if ( (rightubPosorder - rightsubInorder + 1) >= 1)
        {
            buildTreeRec(root->right, inorder, preorder, rightsubInorder, rightubPosorder);
        }
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode * root = NULL;
        if (inorder.size() == 0)
        {
            return root;
        }
        int end = inorder.size() - 1;

        buildTreeRec(root, inorder, preorder, 0, end);
        return root;
    }
};