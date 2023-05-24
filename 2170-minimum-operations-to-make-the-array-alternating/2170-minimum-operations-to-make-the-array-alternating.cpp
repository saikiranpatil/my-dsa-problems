class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size(), ans=0;
        
        if(n==1) return ans;
        
        unordered_map<int, int> count_even, count_odd; 
        int od=(n+1)/2, evn=n/2; //=// count of odd and even number in nums
        
        // cout<<od<<" "<<evn<<endl<<endl;
        
        for(int i=0;i<n;i++){
            if(i%2==0) count_odd[nums[i]]++;
            else count_even[nums[i]]++;
        }
        
        pair<pair<int, int>, pair<int, int>> odd = helper(count_odd);
        pair<pair<int, int>, pair<int, int>> even = helper(count_even);
        
        if(odd.second.first==INT_MIN && even.second.first==INT_MIN) return evn;
        
        int ans11 = od - odd.first.second + evn - even.first.second;
        int ans12 = od - odd.first.second + evn - even.second.second;
        int ans21 = od - odd.second.second + evn - even.first.second;
        
        // cout<<ans11<<" "<<ans12<<" "<<ans21<<endl;
        
        if(odd.first.first != even.first.first) return ans11;
        if(odd.second.first==-1 && even.second.first==-1) return evn;
        if(odd.second.first==-1) return ans12;
        if(even.second.first==-1) return ans21;

        return min(ans12, ans21);
    }
    
    pair<pair<int, int>, pair<int, int>> helper(unordered_map<int, int> count_map){
        pair<pair<int, int>, pair<int, int>> ans = {{-1, -1},{-1, -1}}; 
        //=// ans = {{firstGreaterNum, firstGreaterCount}, {secondGreaterNum, secondGreaterCount}}
        
        for(auto it: count_map){
            int count=it.second;
            int num=it.first;
            
            if(count >= ans.first.second){
                ans.second = ans.first;
                ans.first = it;
            }else if(count >= ans.second.second){
                ans.second = it;
            }
        }
        
        // cout<<ans.first.first<<" "<<ans.first.second<<endl;
        // cout<<ans.second.first<<" "<<ans.second.second<<endl;        
        // cout<<endl;
        
        return ans;
    }
};