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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* from=list1,*to=list1,*tail=list2;
        int i=0;
        while(i++<a-1){
            from=from->next;;
        }
        to=from->next;
        i++;
        while(i++<=b+1){
            to=to->next;
        }
        while(tail->next){
            tail=tail->next;
        }
        from->next=list2;
        tail->next=to;
        return list1;
    }
};