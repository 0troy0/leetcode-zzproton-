/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||head->next==NULL) return head;
        ListNode h(0);
        h.next=head;
        ListNode *p=&h;
        int num=0;
        while(p->next){
            num++;
            p=p->next;
        }
        ListNode *tail=p;
        k=k%num;
        if(k==0) return head;


        p=&h;
        for(int i=0; i<num-k; ++i)
            p=p->next;
        ListNode *q=p->next;
        p->next=NULL;
        h.next=q;
        tail->next=head;

        return h.next;
    }
};