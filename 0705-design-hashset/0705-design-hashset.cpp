class MyHashSet {
public:
    
    ListNode *head=NULL, *curr=NULL;
    
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(contains(key)) return;
        
        curr=new ListNode(key);
        
        if(head==NULL){
            head=curr;
            return;
        }
        
        curr->next=head;
        head=curr;
            
    }
    
    void remove(int key) {
        if(head==NULL) return;
        
        if(head->val==key) {
            head=head->next;
            return;
        }
        
        ListNode* tmp=head;
        
        while(tmp && tmp->next){
            if(tmp->next->val == key) tmp->next=tmp->next->next;
            
            tmp=tmp->next;
        }
    }
    
    bool contains(int key) {
        ListNode* tmp=head;
        
        while(tmp){
            if(tmp->val==key) return true;
            tmp=tmp->next;
        }
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */