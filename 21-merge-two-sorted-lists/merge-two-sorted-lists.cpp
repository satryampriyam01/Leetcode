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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* head=NULL;
        ListNode* current=new ListNode(0);
        head=current;
        ListNode* l1=list1;
        ListNode* l2=list2;
        while(list1 || list2)
        {
            if(l1 && l2)
            {
                if(l1->val<l2->val)
                {
                    current->next=l1;
                    l1=l1->next;
                }
                else
                {
                    current->next=l2;
                    l2=l2->next;
                }
                current=current->next;
            }
            else if(l1)
            {
                current->next=l1;break;
            }
            else
            {
                current->next=l2;break;
            }

        }

        return head->next;
        
        
    }
};