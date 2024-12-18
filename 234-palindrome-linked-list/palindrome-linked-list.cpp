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

ListNode* reverse(ListNode* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    
    ListNode *temp=reverse(head->next);

    ListNode *temp2=head->next;
    temp2->next=head;
    head->next=NULL;
    return temp;

}


    bool isPalindrome(ListNode* head) {
        ListNode* slw=head;
        ListNode* fst=head->next;

        while(slw && fst && fst->next)
        {
            slw=slw->next;
            fst=fst->next->next;
        }
        ListNode* temp=slw->next;
        slw->next=NULL;
        ListNode* temp2=reverse(temp);

        //cout<<slw->val<<endl;
        while(temp2 && head)
        {
            if(temp2->val!=head->val)
            {
                return 0;
            }

            temp2=temp2->next;
            head=head->next;
        }

        return 1;

        
    }
};