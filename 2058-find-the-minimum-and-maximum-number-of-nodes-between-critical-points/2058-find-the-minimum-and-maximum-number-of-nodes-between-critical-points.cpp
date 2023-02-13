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
    
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx=1,prev=head->val;
        ListNode* curr=head->next;
        vector<int> nums;
        
        while(curr){
            if(curr->next && ((prev > curr->val && curr->val < curr->next->val) || (prev < curr->val && curr->val > curr->next->val))){
                nums.push_back(idx);
            }
            prev=curr->val;
            idx++;
            curr=curr->next;
        }
        
        if(nums.size()<2) return {-1,-1};
        
        int ans=INT_MAX;
        for(int i=1;i<nums.size();i++) ans=min(ans,nums[i] - nums[i-1]);
        
        return {ans,nums[nums.size()-1] - nums[0]};
    }
};