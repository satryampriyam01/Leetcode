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

    ListNode* reverse(ListNode * head)
    {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode* rev=reverse(head->next);
        ListNode *temp=head->next;
        temp->next=head;
        head->next=NULL;
        return rev;
    }


    int pairSum(ListNode* head) {
        
        ListNode* slw=head;
        ListNode* fst=head->next;;

        while(fst && fst->next)
        {
            slw=slw->next;
            fst=fst->next->next;
        }
        ListNode* temp2=reverse(slw->next);
        slw->next=NULL;
        ListNode *temp=head;
        int res=0;
        
        while(temp && temp2)
        {
            res=max(res,temp->val+temp2->val);
            temp=temp->next;
            temp2=temp2->next;
        }

        return res;

    }
};