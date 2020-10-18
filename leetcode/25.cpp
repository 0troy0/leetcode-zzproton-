using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//非递归
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||k==1||!head->next) return head;

        vector<ListNode*> p(k+1);
        ListNode h(0);
        p[0]=&h;
        h.next=head;

        while(p[0]){
            int num=0;
            while(num<=k){
                if(p[num]->next&&num+1<=k){
                    p[num+1]=p[num]->next;
                    num++;
                }
                else break;
            }
            if(num<k) break;

            p[1]->next=p[k]->next;
            p[0]->next=p[k];
            for(int i=k; i>=2; --i)
                p[i]->next=p[i-1];

            p[0]=p[1];
        }
        return h.next;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode* cur=head;
        ListNode* tail=dummy;
        while(true){
            int count=0;
            tail=pre;
            while(tail!=NULL&&count<k){
                tail=tail->next; //退出循环后tail指向待反转链表的末尾节点
                count++;
            }
            if(tail==NULL)
                break;
            while(pre->next!=tail){ //pre->next==tail时退出循环
                cur=pre->next;//(1)
                pre->next=cur->next; //(1)  步骤(1):将cur从链表中切出来
                    
                cur->next=tail->next;//(2)
                tail->next=cur; //(2) 步骤(2):将cur添加到tail后
                
            }
            pre=head;
            tail=head;
            head=pre->next;//head指向新的待翻转的链表头
        }
        return dummy->next;
    }
};//这个比自己写的快4ms 是调用vector会加时间吗？

//递归
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p=head;
        int count=0;
        while(p!=nullptr&&count<k){
            p=p->next;
            count++;
        }//不能写!p 为什么？

        if(count==k){
            p=reverseKGroup(p, k);
            while(count>0){
                ListNode* temp=head->next;
                head->next=p;
                p=head;
                head=temp;
                count--;
            }
            head=p;
        }

        return head;
    }
};