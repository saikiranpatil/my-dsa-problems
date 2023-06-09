//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string> nums, ans;
		    
		    helper(s, nums, "");
		    sort(nums.begin(), nums.end());
		    
		    for(int i=0;i<nums.size();i++){
		        ans.push_back(nums[i]);
		        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
		    }
		    
		    return ans;
		}
		
		void helper(string s, vector<string>& nums, string curr){
		    if(s.size() == 0){
		        nums.push_back(curr);
		        return;
		    }
		    
		    for(int i=0;i<s.size();i++){
		        char c = s[i];
		        
		        s.erase(i,1);
		        helper(s, nums, curr + c);
		        s.insert(i, string(1, c));
		    }
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends