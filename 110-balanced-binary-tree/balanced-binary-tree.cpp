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

    int helperheight(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }

        return 1+max(helperheight(root->left),helperheight(root->right));


    }
    
    bool isBalanced(TreeNode* root) {

        if(!root)
        {
            return 1;
        }


        int left=helperheight(root->left);
        int right=helperheight(root->right);

        return (abs(left-right)<2 && isBalanced(root->left) && isBalanced(root->right));



    }
};