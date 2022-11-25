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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || (head && !head->next)) return head;
        
        ListNode* curr = head;
        ListNode* start = head;
        ListNode* end = head;
        
        int n = 0;
        
        while(curr){
            end=curr;
            curr=curr->next;
            n++;
        }
        
        k %= n;
        
        end->next = start;
        
        for(int i=0; i < n-k; i++){
            start=start->next;
            end=end->next;
        }
        
        end->next = NULL;
        
        return start;
    }
};