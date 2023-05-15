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
    int length(ListNode* head){
        int cnt=0;
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n=length(head);
        int i=1;
        ListNode* temp=NULL,*nh=head;
        
        while(nh){
            
            if(i==n-k+1|| i==k){
                if(temp)
                {    swap(temp->val,nh->val);
                
                break;}
                else
                    temp=nh;
            }
            nh=nh->next;
            i++;
        }
        return head;
    }
};