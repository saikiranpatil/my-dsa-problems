class Solution {
public:
    bool checkInclusion(string s1, string s2) {
                vector<int>hash1(26,0),hash2(26,0);

        int n=s1.size(),m=s2.size();

        for(int i=0;i<n;i++){

            hash1[s1[i]-'a']++;

        }

        int i=0,j=0,c=0;

        while(i<m){

            hash2[s2[i]-'a']++;

            if(i>=n) hash2[s2[j++]-'a']--;

            if(hash1==hash2)return true;

            i++;

        }

        return false;
    }
};