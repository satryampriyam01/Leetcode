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
TreeNode *prev;
int ans;
void helperBST(TreeNode* root)
{
    if(!root)
    {
        return ;
    }

    helperBST(root->left);

    if(prev && prev->val>=root->val)
    {
        ans=0;
        return;
    }

    prev=root;
    helperBST(root->right);
}
    bool isValidBST(TreeNode* root) {
        ans=1;
        prev=NULL;

        helperBST(root);
        return ans;
    }
};