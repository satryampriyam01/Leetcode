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

        while(que.size())
        {
            Node *oldNode=que.front();
            Node *newNode=amp[oldNode];
            
            vector<Node*> ngb=oldNode->neighbors;
            que.pop();
  
            vector<Node*> newngb;

            for(int i=0;i<ngb.size();i++)
            {
                Node* oldngbNode=ngb[i];
                Node* newngbNode=NULL;

                if(amp.find(oldngbNode)==amp.end())
                {
                    newngbNode=new Node(oldngbNode->val);
                    amp[oldngbNode]=newngbNode;
                    que.emplace(oldngbNode);
                }
                else
                {
                    newngbNode=amp[oldngbNode];   
                }
                
                newngb.push_back(newngbNode);
            }

           newNode->neighbors=newngb;
        }


        return head;

    }
};