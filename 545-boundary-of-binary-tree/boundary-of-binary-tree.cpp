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

vector<int> res;

void helper_left(TreeNode* root)
{
    if(!root)
    {
        return;
    }

    if(root->left || root->right)
    res.push_back(root->val);
    
    if(!root->left)
    {
        helper_left(root->right);
    }
    else
    {
        helper_left(root->left);
    }

    

}


void helper_leaf(TreeNode *root)
{
    if(!root)
    {
        return ;
    }


    if(!root->left && !root->right)
    {
        res.push_back(root->val);
    }

    helper_leaf(root->left);
    helper_leaf(root->right);


}



void helper_right(TreeNode* root)
{
    if(!root)
    {
        return ;
    }

    
    
    if(!root->right)
    {
        helper_right(root->left);
    }
    else
    {
        helper_right(root->right);
    }

    if(root->left || root->right)
    res.push_back(root->val);

}


    vector<int> boundaryOfBinaryTree(TreeNode* root) {

        res.clear();
        
        if(!root)
        {
            return res;
        }

        res.push_back(root->val);

        helper_left(root->left);
        helper_leaf(root->left);
        helper_leaf(root->right);
        helper_right(root->right);

        return res;    
    }
};