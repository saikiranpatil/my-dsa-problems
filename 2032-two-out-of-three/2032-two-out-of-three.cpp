class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> count(101,0);
        vector<int> ans;
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        
        for(int i=0;i<nums1.size();i++){
            while(i!=nums1.size()-1 && nums1[i+1]==nums1[i]) i++;
            count[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            while(i!=nums2.size()-1 && nums2[i+1]==nums2[i]) i++;
            count[nums2[i]]++;
        }
        for(int i=0;i<nums3.size();i++){
            while(i!=nums3.size()-1 && nums3[i+1]==nums3[i]) i++;
            count[nums3[i]]++;
        }
        for(int i=0;i<count.size();i++){
            if(count[i]>1) ans.push_back(i);
        }
        
        return ans;
    }
};