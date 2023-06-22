//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        int count_5 = 0, count_10 = 0;
        for(int i = 0; i < N; i++) {
            if(bills[i] == 5) {
                count_5++;
            } else if(bills[i] == 10) {
                if(count_5 > 0) {
                    count_5--;
                    count_10++;
                } else {
                    return false;
                }
            } else if(bills[i] == 20) {
                if(count_10 > 0 && count_5 > 0) {
                    count_10--;
                    count_5--;
                } else if(count_5 >= 3) {
                    count_5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends