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

    void fillVal(TreeNode * tree, int &counter)
    {
        if (tree == NULL)
        {
            return;
        }

        if (tree->left != NULL)
        {
            fillVal(tree->left, counter);
        }

        tree->val = counter++;

        if (tree->right != NULL)
        {
            fillVal(tree->right, counter);
        }
    }

    TreeNode * getTreeHardCopy(TreeNode * tree)
    {
        if (tree == NULL)
        {
            return NULL;
        }

        TreeNode * hardcopy = new TreeNode(0);
        hardcopy->val = tree->val;
        if ( tree->left != NULL )
        {
            hardcopy->left = getTreeHardCopy(tree->left);
        }

        if ( tree->right != NULL )
        {
            hardcopy->right = getTreeHardCopy(tree->right);
        }

        return hardcopy;
    }

    vector<TreeNode *> genktre(int n)
    {
        vector<TreeNode *> alltree;
        if ( n == 0)
        {
            alltree.push_back( NULL );
            return alltree;
        }

        if ( n == 1)
        {
            TreeNode * newtree = new TreeNode(0);
            alltree.push_back(newtree);
            return alltree;
        }

        for (int i = 0; i < n; i++)
        {
            vector<TreeNode *> a = genktre(i);
            vector<TreeNode *> b = genktre(n - 1 - i);
            
            for (int j = 0; j < a.size(); j++)
            {
                for (int k = 0; k < b.size(); k++)
                {
                    TreeNode * copya = getTreeHardCopy(a[j]);
                    TreeNode * copyb = getTreeHardCopy(b[k]);
                    TreeNode * newtree = new TreeNode(0);
                    newtree->left = copya;
                    newtree->right = copyb;
                    alltree.push_back(newtree);
                }
            }

            // memory leak here, a, b should be cleared, but let's skip that....
        }
    }

    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> k = genktre(n);
        for (int i = 0; i < k.size(); i++)
        {
            int counter = 1;
            fillVal( k[i], counter);
        }
        return k;
    }
};