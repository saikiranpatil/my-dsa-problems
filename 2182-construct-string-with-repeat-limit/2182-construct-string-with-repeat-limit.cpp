class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char, int>> pq;
        map<char, int> mp;
        string ans = "";

        for (auto ch : s) mp[ch]++;
        for (auto ch : mp) pq.push({ch.first,ch.second});

        while (!pq.empty())
        {
            auto x = pq.top();
            int k = repeatLimit;
            
            int freq1 = x.second;
            char ch1 = x.first;
            pq.pop();

            int mi = min(k, freq1);
            freq1 -= mi;
            ans += string(mi, ch1);

            if (pq.empty() || freq1 == 0) continue;

            auto y = pq.top();
            int freq2 = y.second;
            char ch2 = y.first;
            pq.pop();

            ans += ch2;
            freq2--;

            if (freq1 > 0) pq.push({ch1,freq1});
            if (freq2 > 0) pq.push({ch2,freq2});
        }

        return ans;
    }
};