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
    int closestValue(TreeNode* root, double target) {


        if(root==NULL)
        {
            return -1;
        }
       double result=root->val;

       queue<TreeNode*> que;
       que.push(root);

       while(que.size())
       {
            int n=que.size();
            while(n--)
            {
                TreeNode* temp=que.front();
                que.pop();

                if(abs(temp->val-target)<=abs(result-target))
                {
                    if(abs(temp->val-target)==abs(result-target))
                    {
                            if(temp->val<target)
                            {
                                result=temp->val;
                            }
                    }
                    else
                    {
                        result=temp->val;
                    }
                }
                if(temp->left)
                {
                    que.push(temp->left);
                }
                if(temp->right)
                {
                    que.push(temp->right);
                }
 
            }
       }


       return result;



    }
};