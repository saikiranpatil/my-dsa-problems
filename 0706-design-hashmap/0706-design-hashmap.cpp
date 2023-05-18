class MapNode {
public:
    int key;
    int value;
    MapNode *next;
    
    MapNode(int ky, int val){
        key=ky;
        value=val;
        next=NULL;
    }
};

class MyHashMap {
public:
    MapNode *head=NULL;
    
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        bool found=false;
        
        MapNode *curr=head;
        
        while(curr){
            if(curr->key==key){
                curr->value=value;
                found=true;
                
                return;
            }
            
            curr=curr->next;
        }
        
        if(!found){
            MapNode *neww= new MapNode(key, value);
            
            neww->next=head;
            head=neww;
        }
    }
    
    int get(int key) {
        MapNode *tmp=head;
        
        while(tmp){
            if(tmp->key==key) return tmp->value;
            
            tmp=tmp->next;
        }
        
        return -1;
    }
    
    void remove(int key) {
        if(!head) return;
        if(head->key==key){
            head=head->next;
        }
        
        MapNode* tmp=head;
        
        while(tmp && tmp->next){
            if(tmp->next->key==key){
                tmp->next=tmp->next->next;
                return;
            }
            
            tmp=tmp->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */