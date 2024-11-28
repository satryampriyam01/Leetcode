/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<int,vector<int>> amp;

        queue<TreeNode*> que;

        que.push(root);

        while(que.size())
        {
            int n=que.size();

            while(n--)
            {
                TreeNode* temp=que.front();
                que.pop();

                if(temp->left)
                {
                    amp[temp->val].push_back(temp->left->val);
                    amp[temp->left->val].push_back(temp->val);
                    que.push(temp->left); 
                }

                if(temp->right)
                {
                    amp[temp->val].push_back(temp->right->val);
                    amp[temp->right->val].push_back(temp->val);
                    que.push(temp->right);
                }
            }
        }

        vector<int> res;
        if(amp[target->val].size()==0)
        {
            return res;
        }
        if(k==0)
        {
            res.push_back(target->val);
            return res;
        }

        queue<int> que2;
        vector<int> vst(10001);
        vst[target->val]=1;
        que2.push(target->val);
        
        while(k--)
        {
            int n=que2.size();
           // cout<<n<<endl;
            while(n--)
            {
                int temp=que2.front();
                que2.pop();
               // cout<<temp<<endl;
                if(k==0)
                {
                    
                    vector<int> v=amp[temp];
                    for(int i=0;i<v.size();i++)
                    {
                        if(vst[v[i]]==0)
                        res.push_back(v[i]);
                    }
                }
                else
                {
                    vector<int> v=amp[temp];
                    for(int i=0;i<v.size();i++)
                    {
                        if(vst[v[i]]==0)
                        {
                            que2.push(v[i]);
                            vst[v[i]]++;
                        }
                    }
                }
            }

            //cout<<endl;
        }


        return res;
        
    }
};