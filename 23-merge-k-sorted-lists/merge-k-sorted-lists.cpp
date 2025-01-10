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


ListNode * helper_merge(ListNode* left,ListNode* right)
{

    ListNode *head=new ListNode(-1);
    ListNode *temp=head;

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


            while(left!=NULL)
            {
                temp->next=left;
                left=left->next;
                 temp=temp->next;
            }

            while(right!=NULL)
            {
                temp->next=right;
                right=right->next;
                 temp=temp->next;
            }

    return head->next;

}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n=lists.size();

        if(n==0)
        {
            return NULL;
        }

        if(n==1)
        {
            return lists[0];
        }


        ListNode *prev= new ListNode(INT_MIN);

        for(int i=0;i<n;i++)
        {
            prev=helper_merge(prev,lists[i]);
        }

        return prev->next;


    }
};