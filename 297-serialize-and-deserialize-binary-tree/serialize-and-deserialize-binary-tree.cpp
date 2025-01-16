/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root)
        {
            return "NULL,";
        }

        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      

       queue<string> que;
        string s;
        
        for(int i=0;i<data.size();i++)
        {
            

            if(data[i]==',')
            {
                que.push(s);
                s.clear();
                continue;
            }
            s+=data[i];
        }

        if(s.size())
        {
            que.push(s);
        }

        return helper_deserialize(que);

    }


    TreeNode* helper_deserialize(queue<string> &que)
    {
        string s=que.front();
        que.pop();
        
        if(s=="NULL")
        {
            return NULL;
        }

        TreeNode* root=new TreeNode(stoi(s));
        root->left=helper_deserialize(que);
        root->right=helper_deserialize(que);
        
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));