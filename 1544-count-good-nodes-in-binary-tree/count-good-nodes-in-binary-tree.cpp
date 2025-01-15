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

int helperGood(TreeNode* root,int val)
{   
    int goodNode=0;
    if(!root)
    {
        return goodNode;
    }

    int left=helperGood(root->left,max(val,root->val));
    int right=helperGood(root->right,max(val,root->val));
    if(root->val>=val)
    {
        
        return 1+left+right;
    }

    return left+right;

    



}

    int goodNodes(TreeNode* root) {
        
        if(!root)
        {
            return 0;
        }
       return helperGood(root,INT_MIN);
    }
};