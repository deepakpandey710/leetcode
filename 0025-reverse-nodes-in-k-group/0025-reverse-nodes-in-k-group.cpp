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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        for(int i=0;i<k;i++){
            if(!temp)return head;
            temp=temp->next;
        }
        
        ListNode* cur=head,*prev=NULL,*nxt=NULL;
        int i=0;
        while(i<k){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            i++;
        }
        if(nxt){
            head->next=reverseKGroup(cur,k);
        }
        return prev;
    }
};