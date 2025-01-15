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

    TreeNode *helper(vector<int>& preorder,int preSE,int preEN,vector<int>& inorder,int inSE,int inEN)
    {

        if(preSE>preEN)
        {
            return NULL;
        }

        if(preSE==preEN)
        {
            TreeNode* root=new TreeNode(preorder[preSE]);
            return root;
        }

        TreeNode* root=new TreeNode(preorder[preSE]);

        int lef=inSE;
        while(lef<=inEN && inorder[lef]!=preorder[preSE])
        {
            lef++;
        }

        int count=lef-inSE;

        root->left=helper(preorder,preSE+1,preSE+count,inorder,inSE,inSE+lef-1);
        root->right=helper(preorder,preSE+count+1,preEN,inorder,lef+1,inEN);
        
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();

        TreeNode *root=helper(preorder,0,n-1,inorder,0,n-1);
        return root;  
    }
};