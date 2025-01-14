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


bool isSameHelper(TreeNode* root,TreeNode*subRoot)
{
    if(!root && !subRoot)
    {
        return 1;
    }

    if(!root || !subRoot)
    {
        return false;
    }

    if(root->val!=subRoot->val)
    {
        return 0;
    }

    bool left=isSameHelper(root->left,subRoot->left);
    bool right=isSameHelper(root->right,subRoot->right);

    return left && right;

}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(!root && !subRoot)
        {
            return 1;
        }

        if(!root || !subRoot)
        {
            cout<<root<<" "<<subRoot<<endl;
            return false;
        }

        

        if(root->val==subRoot->val)
        {
           // cout<<"Hello"<<endl;
            bool r= isSameHelper(root,subRoot);
           // cout<<r<<endl;
            if(r)
            {
                return r;
            }
        }

        bool left=isSubtree(root->left,subRoot);
        bool right=isSubtree(root->right,subRoot);

        return left || right;
    }
};