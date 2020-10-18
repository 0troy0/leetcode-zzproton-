/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *x=l1, *y=l2, *temp1, *ans, *temp2;
        ans=new ListNode(0);
        temp1=ans;
        int a, b, carry=0;
        while (x!=NULL||y!=NULL){
            if(x!=NULL){
                a=x->val;
                x=x->next;
            }
            else a=0;
            if(y!=NULL){
                b=y->val;
                y=y->next;
            }
            else b=0;
            temp2=new ListNode(0);
            temp2->val=a+b+carry;
            carry=temp2->val/10;
            temp2->val=temp2->val%10;
            temp1->next=temp2;
            temp1=temp2;
        }
        if(carry>0){
            temp2=new ListNode(carry);
            temp1->next=temp2;
            temp1=temp2;
        }
        ans=ans->next;
        return ans;
    }
};

//Yining's code

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode result (0), *ptr = &result;
        while (l1 || l2 || sum){
          sum += (l1? l1->val : 0) + (l2? l2->val : 0);
          l1 = l1? l1 -> next : NULL;
          l2 = l2? l2 -> next : NULL;
          ptr->next = new ListNode (sum%10);
          ptr = ptr->next;
          sum = sum/10;
        }
        
        return result.next;
    }
};