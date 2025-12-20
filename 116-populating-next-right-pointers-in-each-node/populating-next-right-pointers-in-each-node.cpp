/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*> que;

        if(!root)
        {
            return root;
        }
        que.emplace(root);

        while(que.size())
        {
            int n=que.size();
            while(n--)
            {
                Node* temp=que.front();
                que.pop();

                if(n==0)
                {
                    temp->next=NULL;
                }
                else{
                    temp->next=que.front();
                }

                if(temp->left)
                {
                    que.emplace(temp->left);
                }
                if(temp->right)
                {
                    que.emplace(temp->right);
                }
            }
        }

        return root;

    }
};