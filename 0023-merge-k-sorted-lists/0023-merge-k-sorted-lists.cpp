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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)return NULL;
        ListNode* head=lists[0];
        int i=1;
        while(i<n){
            head=merge(head,lists[i++]);
        }
        return head;
    }
    ListNode* merge(ListNode* &p1,ListNode* &p2){
        ListNode* dummy=new ListNode(-1);
        ListNode* head=dummy;
        while(p1 && p2){
            if(p1->val<p2->val){
                dummy->next=p1;
                dummy=dummy->next;
                p1=p1->next;
            }
            else{
                dummy->next=p2;
                dummy=dummy->next;
                p2=p2->next;
            }
        }
        while(p1){
            dummy->next=p1;
            dummy=dummy->next;
            p1=p1->next;
        }
        while(p2){
            dummy->next=p2;
            dummy=dummy->next;
            p2=p2->next;
        }
        return head->next;
    }
};