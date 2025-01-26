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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head=new ListNode(-1);

        int carry=0;
        ListNode* curr=head;

        while(l1 || l2)
        {
            if(l1 && l2)
            {
                int val=l1->val+l2->val+carry;
                ListNode* temp=new ListNode(val%10);
                carry=val/10;
                curr->next=temp;
                curr=curr->next;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1)
            {
                int val=l1->val+carry;
                ListNode* temp=new ListNode(val%10);
                carry=val/10;
                curr->next=temp;
                curr=curr->next;
                l1=l1->next;
            }
            else if(l2)
            {
                int val=l2->val+carry;
                ListNode* temp=new ListNode(val%10);
                carry=val/10;
                curr->next=temp;
                curr=curr->next;
                l2=l2->next;
            }
        }


        if(carry)
        {
            int val=carry;
                ListNode* temp=new ListNode(val%10);
                carry=val/10;
                curr->next=temp;
                curr=curr->next;
        }


        return head->next;
    }
};