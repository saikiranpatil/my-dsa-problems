class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> st;
        
        for(auto it: arr) st.insert(it);
        
        int i=1;
        
        for(;k;i++){
            if(st.find(i)==st.end()) k--;
        }
        
        return --i;
    }
};