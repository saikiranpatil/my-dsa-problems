class CountIntervals {
public:
    map<int, int> m;
    int cnt = 0;
    
    CountIntervals() {}
    
    void add(int left, int right) {
        auto it = m.upper_bound(left);
        
        if (it != begin(m) && prev(it)->second >= left) it = prev(it);
        
        for (; it != end(m) && it->first <= right; m.erase(it++)) {
            left = min(left, it->first);
            right = max(right, it->second);
            cnt -= it->second - it->first + 1;
        }
        
        cnt += right - left + 1;
        m[left] = right;
    }
    
    int count() {return cnt;}
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */