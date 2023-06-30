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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* tmp=head;
        
        while(tmp!=NULL){
            size++;
            tmp=tmp->next;
        }
        
        tmp=head;
        
        if(n==size){
            return head->next;
        }
        
        for(int i=0;i<size-n-1;i++){
            tmp=tmp->next;
        }
        
        if (tmp->next!=NULL&&tmp->next->next!=NULL){
            tmp->next=tmp->next->next;
        }else{
            tmp->next=NULL;
        }
        
        return head;
    }
};