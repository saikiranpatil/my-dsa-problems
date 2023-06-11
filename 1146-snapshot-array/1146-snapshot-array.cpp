class SnapshotArray {
public:
    vector<unordered_map<int, int>> snaps;
    int snapId;
    
    SnapshotArray(int length) {
        snaps.resize(length);
        snapId=0;
    }
    
    void set(int index, int val) {
        snaps[index][snapId]=val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        while (snap_id >= 0 && snaps[index].find(snap_id) == snaps[index].end()){
            snap_id--;
        }
        
        if (snap_id < 0){
            return 0;
        }
        
        return snaps[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */