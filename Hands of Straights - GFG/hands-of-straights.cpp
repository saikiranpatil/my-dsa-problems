//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N%groupSize>0) return 0;
        
        map<int,int> mp;
        for(auto it: hand){
            mp[it]++;
        }
        
        while(!mp.empty()){
            int a= mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mp[a+i]==0) return 0;
                else if(--mp[a+i]==0) mp.erase(a+i);
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends