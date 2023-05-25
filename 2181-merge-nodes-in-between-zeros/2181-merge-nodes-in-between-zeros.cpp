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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *left=head, *right=head->next;
        
        while(right){
            int sum=0;
            
            while(right && right->val!=0){
                sum+=right->val;
                right=right->next;
            }
            
            right->val=sum;
            left->next=right;
            left=left->next;
            right=right->next;
        }
        
        return head->next;
    }
};