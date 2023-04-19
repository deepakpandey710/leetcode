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
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        queue<int> q;
        ListNode *curr = head;
        int n=length(head);
        if(k==0||n==0)return head;
        k=k%n;
        while(curr) {
            cout<<q.size()<<curr->val;
            if(q.size() != k) {
                q.push(curr->val);
                curr=curr->next;
                continue;
            }
            q.push(curr->val);
            curr->val = q.front();
            q.pop();
            curr = curr->next;
            ListNode* temp=curr;
        }
        curr = head;
        while(!q.empty()&& curr!=NULL) {
            curr->val = q.front();
            q.pop();
            curr = curr->next;
        }

        return head;
    }
};