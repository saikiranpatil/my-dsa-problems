class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        string ans="";
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        for(int i=0;i<arr.size();i++){
            if(k==0) break;
            if(mp[arr[i]]==1){
                 k--;
                ans=arr[i];
            }
            cout<<arr[i]<<" "<<mp[arr[i]]<<" "<<k<<endl;
        }
        
        return k== 0 ? ans : "";
    }
};