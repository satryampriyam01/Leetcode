/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL)
        {
            return NULL;
        }

        Node* new_head=new Node(head->val);
        Node* curr=head;
        Node* curr_new=new_head;
        
        unordered_map<Node*,Node*> amp_index;//Node -> randomIndex
        unordered_map<Node*,Node*> amp_new;//index->Node

        amp_index[curr]=curr->random;    
        amp_new[curr]=curr_new;

        curr=curr->next;

        while(curr)
        {
            Node *temp=new Node(curr->val);
            
            amp_index[curr]=curr->random;//randomIndex
            amp_new[curr]=temp;
            
            curr_new->next=temp;
            curr_new=temp;

            curr=curr->next;
        }

        curr_new=new_head;
        curr=head;

        while(curr)
        {  
            Node *randomForOld=amp_index[curr];
            curr_new->random=amp_new[randomForOld];
            
            curr_new=curr_new->next;
            curr=curr->next;
        }



        return new_head;
    }
};