class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        int ans=0;
        double curr = sum;
        sum/=2.0;
        
        priority_queue<double> pq(nums.begin(), nums.end());
        
        while(curr>sum){
            double top = pq.top();
            pq.pop();
            
            top/=2;
            curr-= top;
            pq.push(top);
            
            ans++;
        }
        
        return ans;
    }
};