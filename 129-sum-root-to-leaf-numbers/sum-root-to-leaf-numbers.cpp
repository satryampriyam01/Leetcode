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

    void helper(TreeNode* root, int n)
    {
        if(root==NULL)
        {
            return ;
        }
        n=n*10+root->val;
        if(root->left==NULL && root->right==NULL)
        {    
            res.push_back(n);
            return ;
        }

        helper(root->left,n);
        helper(root->right,n);

    }


    int sumNumbers(TreeNode* root) {
        if(!root)
        {
            return 0;
        }

      
        res.clear();
        helper(root,0);
        int answer=0;

        for(int i=0;i<res.size();i++)
        {
            answer+=res[i];
        } 

        return answer;



        

    }
};