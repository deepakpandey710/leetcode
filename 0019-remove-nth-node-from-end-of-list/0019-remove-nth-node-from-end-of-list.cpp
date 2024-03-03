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
    int size(ListNode* head){
        int cnt=0;
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=size(head);
        if(length==1 && n==1)return NULL;
        if(length-n==0)return head->next;
        int i=1;
        ListNode* temp=head;
        while(i<length-n){
            temp=temp->next;
            i++;
        }
        if(temp->next){
            temp->next=temp->next->next;
        }else{
            temp->next=NULL;
        }
        return head;
    }
};