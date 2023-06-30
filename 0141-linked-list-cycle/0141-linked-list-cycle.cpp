/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        ListNode *s=head, *f=head;
        if(head==NULL || head->next==NULL) return false;

        s= s->next;
        f= f->next->next;

        while(s && f)
        {
            if(s==f) return true;
            s= s->next;

            if(f->next==NULL) return false;
            f= f->next->next;
        }
        return false;
    }
};