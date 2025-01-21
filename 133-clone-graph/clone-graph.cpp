/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
       if(!node)
       {
        return node;
       }
        
        unordered_map<Node*,Node*> amp;

        Node *head=new Node(1);

        amp[node]=head;

        queue<Node*> que;
        que.emplace(node);

        vector<int> vst(10001);
        
        while(que.size())
        {
            Node* old=que.front();
            vector<Node*> ngb=old->neighbors;

            que.pop();

            Node *newNode=amp[old];
            vector<Node*> newNeighbours;

            for(int i=0;i<ngb.size();i++)
            {
                Node* ngbOldNode=ngb[i];
                Node* ngbNewNode=NULL;
                
                if(amp.find(ngbOldNode)==amp.end())
                {
                    ngbNewNode=new Node(ngbOldNode->val);
                    amp[ngbOldNode]=ngbNewNode; 
                    que.emplace(ngbOldNode);                
                }
                else
                {
                    ngbNewNode=amp[ngbOldNode];
                }

                    newNeighbours.push_back(ngbNewNode);

            }
            newNode->neighbors=newNeighbours;

        }



        return head;
        
    }
};