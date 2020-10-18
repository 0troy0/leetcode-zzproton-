#include<vector>
#include<queue>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//1分治法
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size()-1);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right){
        if(left>right) return nullptr;
        if(left==right) return lists[left];
        int mid=(left+right)/2;

        ListNode* p=mergeKLists(lists, left, mid);
        ListNode* q=mergeKLists(lists, mid+1, right);
        ListNode head(0);
        ListNode* cur=&head;

        while(p&&q){
            if(p->val<q->val){
                cur->next=p;
                p=p->next;
            }
            else{
                cur->next=q;
                q=q->next;
            }
            cur=cur->next;
        }

        cur->next=p?p:q;
        return head.next;
    }
};

//2优先队列
class Solution{
public:
    struct cmp{
        bool operator()(ListNode* p, ListNode* q){
            return p->val>q->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.size()==0) return nullptr;
        ListNode head(0);
        ListNode* cur=&head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> dic;
        for(ListNode* l:lists)
            if(l) dic.push(l);
        
        while(!dic.empty()){
            cur->next=dic.top();
            cur=cur->next;
            dic.pop();
            if(cur->next) dic.push(cur->next);
        }
        return head.next;
    }
};