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

    int mini=0;
    int maxi=0;
  unordered_map<int,priority_queue<pair<int,int>>> amp;
    void helper(TreeNode* root,int x,int y)
    {
        if(!root)
        {
            return;
        }

        amp[x].push(make_pair(y,root->val));
       // cout<<x<<" "<<y<<endl;
        mini=min(x,mini);
        maxi=max(maxi,x);

        if(root->left)
        {
            helper(root->left,x-1,y+1);
        }

        if(root->right)
        {
            helper(root->right,x+1,y+1);
        }



    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        amp.clear();
        vector<vector<int>> answer;
        //cout<<mini<<" "<<maxi<<endl;
        helper(root,0,0);

        for(int i=mini;i<=maxi;i++)
        {
            vector<int> result;
            if(amp[i].size())
            {
                priority_queue<pair<int,int>> pq=amp[i];
                
                while(pq.size())
                {
                    result.push_back(pq.top().second);
                    pq.pop();
                }
            }
            reverse(result.begin(),result.end());
            answer.push_back(result);
        }

        return answer;

    }

};