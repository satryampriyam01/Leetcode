/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

ListNode* helper_merge(ListNode* left,ListNode* right)
{
    ListNode* head= new ListNode(INT_MIN);
    ListNode*temp= head;

    while(left && right)
    {
        if(left->val<right->val)
        {
            temp->next=left;
            left=left->next;
            
        }
        else
        {
            temp->next=right;
            right=right->next;
        }
        temp=temp->next;
    }

    while(left)
    {
            temp->next=left;
            left=left->next;
            temp=temp->next;
    }


    while(right)
    {
        temp->next=right;
        right=right->next;
        temp=temp->next;
    }

    return head->next;
}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        

        int n=lists.size();
        ListNode *prev=new ListNode(INT_MIN);
        for(int i=0;i<n;i++)
        {
            prev=helper_merge(prev,lists[i]);
        }

        return prev->next;

    }
};