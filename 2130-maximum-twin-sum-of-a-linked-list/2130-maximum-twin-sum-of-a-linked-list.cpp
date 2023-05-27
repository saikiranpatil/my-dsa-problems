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
    int pairSum(ListNode* head) {
        int ans=0;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        ListNode *tmp;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev = slow;
        slow = slow->next;
        prev->next = nullptr;
        
        while (slow) {
            tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }

        fast = head;
        slow = prev;

        while (slow) {
            ans=max(ans,slow->val + fast->val);
            
            slow=slow->next;
            fast=fast->next;
        }

        

        return ans;
    }
};