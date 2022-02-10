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
        ListNode *sumtemp = new ListNode((l1->val+l2->val)%10);
        ListNode* fsum = sumtemp;
        int carry=0;
        if(l1->val+l2->val>9)
            carry=1;
        while(l1->next!=NULL && l2->next!=NULL){
            //cout<<sum<<endl;
            if(l1->next)
            l1 = l1->next;
            if(l2->next)
            l2 = l2->next;
            sumtemp->next = new ListNode((l1->val+l2->val+carry)%10);
            sumtemp=sumtemp->next;
            if(l1->val+l2->val+carry>9)
                carry=1;
            else
                carry=0;
        }
        while(l1->next!=NULL){
            l1=l1->next;
            sumtemp->next = new ListNode((l1->val+carry)%10);
             if(l1->val+carry>9)
                carry=1;
            else
                carry=0;
            sumtemp=sumtemp->next;
        }
        while(l2->next!=NULL){
            l2=l2->next;
            sumtemp->next = new ListNode((l2->val+carry)%10);
             if(l2->val+carry>9)
                carry=1;
            else
                carry=0;
            sumtemp=sumtemp->next;
        }
        if(carry==1)
            sumtemp->next = new ListNode(1);
        return fsum;
    }
};
