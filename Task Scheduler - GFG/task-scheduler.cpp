//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        int count[26] = {0};
        for(auto it: tasks)
        {
            count[it-'A']++;
        }
        int mx = *max_element(count, count+26);
        int tmp = 0;
        for(int i = 0;i<26;i++)
        {
            if(mx == count[i])
            tmp++;
        }
        return max(N,(mx + (mx-1)*K + tmp-1));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends