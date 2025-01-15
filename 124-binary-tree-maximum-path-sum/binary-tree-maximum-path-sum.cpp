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
int maxi=INT_MIN;

int helper(TreeNode* root)
{
    if(!root)
    {
        return 0;
    }

    int left=max(helper(root->left),0);
    int right=max(helper(root->right),0);

    maxi=max(maxi,left+right+root->val);

    return max(root->val+left,root->val+right);
}

    int maxPathSum(TreeNode* root) {
        maxi=INT_MIN;
        helper(root);
        return maxi;
    }
};