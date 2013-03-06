/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

    void connectArtBT(TreeLinkNode *root) 
    {
        if ( root == NULL ) return ;
        TreeLinkNode * nextLevelStarter = NULL;
        TreeLinkNode * curLevelNode = root;
        TreeLinkNode * nextLevelNode;
        while ( curLevelNode != NULL)
        {
            if ( curLevelNode->left != NULL)
            {
                if ( nextLevelStarter == NULL)
                {
                    nextLevelStarter = curLevelNode->left;
                    nextLevelNode = curLevelNode->left;
                }
                else
                {
                    nextLevelNode->next = curLevelNode->left;
                    nextLevelNode = nextLevelNode->next;
                }
            }

            if ( curLevelNode->right != NULL)
            {
                if ( nextLevelStarter == NULL)
                {
                    nextLevelStarter = curLevelNode->right;
                    nextLevelNode = curLevelNode->right;
                }
                else
                {
                    nextLevelNode->next = curLevelNode->right;
                    nextLevelNode = nextLevelNode->next;
                }
            }

            curLevelNode = curLevelNode->next;
        }

        connectArtBT(nextLevelStarter);
        
    }

    void connectFullBT(TreeLinkNode *root) 
    {
        if ( root == NULL ) return ;
        if ( root->left == NULL) return;
        root->left->next = root->right;
        TreeLinkNode * left, * right;
        left = root->left;
        right = root->right;
        while ( left->right != NULL)
        {
            left->right->next = right->left;
            left = left->right;
            right = right->left;
        }
        connectFullBT( root->left);
        connectFullBT( root->right);
    }

    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        connectArtBT(root);
    }
};