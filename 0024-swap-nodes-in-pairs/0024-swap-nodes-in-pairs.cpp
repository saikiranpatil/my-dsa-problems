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
        if(!head) return head;
        
        ListNode *first = head;
        ListNode *second=head->next;
        
        while(first && second){
            int tmp=first->val;
            
            first->val=second->val;
            second->val=tmp;
            
            first=second->next;
            if(first) second=first->next;
        }
        
        return head;
    }
};