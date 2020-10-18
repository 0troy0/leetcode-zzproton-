struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//1非递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode h(0);
        h.next=head;
        ListNode* p=&h;
        ListNode* q=head;

        while(q){
            ListNode* r=q->next;
            if(!r) break;

            p->next=r;
            q->next=r->next;
            r->next=q;

            p=q;
            q=q->next;
        }

        return h.next;
    }
};

//2递归
class Solution{
public:
    ListNode* swapPairs(ListNode* head){
        if(!head||!head->next) return head;

        ListNode* p=head->next;
        head->next=swapPairs(p->next);
        p->next=head;

        return p;
    }
};