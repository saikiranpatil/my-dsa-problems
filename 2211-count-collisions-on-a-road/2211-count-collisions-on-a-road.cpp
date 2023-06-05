class Solution {
public:
    int countCollisions(string directions) {
        int n =directions.size();
        int start = 0;
        int end = n-1;
        int ans=0;
        
        while(start<n && directions[start] == 'L') start++;
        while(end>=0 && directions[end] == 'R') end--;
        
        for(int i=start;i<=end;i++){
            if(directions[i] != 'S') ans++;
        }
        
        return ans;
    }
};