/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* prev=NULL;
    bool helper(TreeNode* root)
    {
        if(!root)
        {
            return 1;
        }

        bool left=helper(root->left);

        if(prev && prev->val>=root->val)
        {
            return 0;
        }

        prev=root;
        bool right=helper(root->right);

        return left*right;
    }


    bool isValidBST(TreeNode* root) {
        
        if(!root)
        {
            return 1;
        }

        bool k=helper(root);


        return k;

    }
};