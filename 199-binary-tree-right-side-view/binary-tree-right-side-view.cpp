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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        queue<TreeNode*> que;

        if(root==NULL)
        {
            return result;
        }
        
        que.push(root);

        while(que.size())
        {
            int n=que.size();

            while(n--)
            {
                TreeNode* temp=que.front();
                que.pop();

                if(n==0)
                {
                    result.push_back(temp->val);
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