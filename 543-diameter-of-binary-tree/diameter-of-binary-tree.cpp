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

int res=0;
    int helperDiameter(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }

        int left=helperDiameter(root->left);
        int right=helperDiameter(root->right);

        res=max(res,left+right);
        
        return 1+max(left,right);


    }


    int diameterOfBinaryTree(TreeNode* root) {

        int r= helperDiameter(root);
        return res;
    }
};