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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *nh=new ListNode(0);
        nh->next=head;
        ListNode* prev=nh,*cur=head;
        while(cur && cur->next){
            prev->next=cur->next;
            prev=prev->next;
            cur->next=prev->next;
            prev->next=cur;
            prev=cur;
            cur=cur->next;
        }
        return nh->next;
    }
};