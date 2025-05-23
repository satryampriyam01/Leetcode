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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        
        vector<vector<int>> res;
        if(!root)
        {
            return res;
        }

        queue<TreeNode*> que;
        if(root)
        {
            que.push(root);
        }
        
        while(que.size())
        {
            int n=que.size();
            vector<int> r;
            while(n--)
            {
                TreeNode* temp=que.front();
                que.pop();

                r.push_back(temp->val);

                if(temp->left)
                {
                    que.push(temp->left);
                }

                if(temp->right)
                {
                    que.push(temp->right);
                }

            }

            res.push_back(r);
        }


        return res;
    }
};