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
private:
    ListNode* main;
    int sz;
    
public:
    Solution(ListNode* head) {
        main = head;
        sz=0;
        
        ListNode* tmp = head;
        
        while(tmp != NULL){
            sz++;
            tmp=tmp->next;
        }
    }
    
    int getRandom() {
        int idx = rand() % sz;
        int ans=-1;
        
        ListNode* curr = main;
        while (curr != NULL && idx--) curr = curr->next; 
        if (curr != NULL) ans = curr->val; 
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */