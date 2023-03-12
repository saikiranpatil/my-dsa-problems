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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        
        return helper(lists, 0, lists.size());
    }
    
    ListNode* helper(vector<ListNode*>& lists, int low, int high){
        if(low + 1 == high) return mergeTwoLists(lists[low], NULL); 
        return mergeTwoLists(helper(lists, low, (high + low)/2), helper(lists, (high + low)/2, high));
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL || list2==NULL) return list1==NULL ? list2 : list1;
        
        ListNode* ans =NULL, *head = NULL;
        
        if(list1->val < list2->val){
            head = new ListNode(list1->val);
            list1=list1->next;
        }else{
            head = new ListNode(list2->val);
            list2=list2->next;
        }
        
        ans = head;
        
        while(list1!=NULL && list2!=NULL){
            if(list1->val > list2->val){
                head->next = new ListNode(list2->val);
                list2=list2->next;
            }else{
                head->next = new ListNode(list1->val);
                list1=list1->next;
            }
            head=head->next;
        }
        
        if(list1) head->next = list1;
        if(list2) head->next = list2;
        
        return ans;
    }
};