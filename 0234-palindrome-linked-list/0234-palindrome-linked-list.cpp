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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr, *tmp;
        
        // Find the middle of the linked list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the linked list
        prev = slow;
        slow = slow->next;
        prev->next = nullptr;
        
        while (slow) {
            tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        
        // Compare the reversed second half with the first half
        fast = head;
        slow = prev;
        
        while (slow) {
            if (slow->val != fast->val)
                return false;
            
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
    }
};
