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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next=head;
        ListNode* cur=dummy;
        int prefix=0;
        map<int,ListNode*>mpp;
        while(cur){
            prefix+=cur->val;
            if(mpp.count(prefix)){
                cur=mpp[prefix]->next;
                int p=prefix+cur->val;
                while(p!=prefix){
                    mpp.erase(p);
                    cur=cur->next;
                    p+=cur->val;
                }
                mpp[prefix]->next=cur->next;
            }else{
                mpp[prefix]=cur;
            }
            cur=cur->next;
        }
        return dummy->next;
    }
    
};