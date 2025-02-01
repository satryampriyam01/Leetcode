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

bool helper(TreeNode *root,TreeNode *root2)

{
    if(!root && !root2)
    {
        return true;
    }

    if(!root || !root2)
    {
       // cout<<1<<endl;
        return false;
    }
    
   
    bool lef=helper(root->left,root2->right);
    bool rgt=helper(root->right,root2->left);


    return (lef && rgt && root->val==root2->val);

}

    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        return helper(root->left,root->right); 

        
    }
};