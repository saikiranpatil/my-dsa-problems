class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        vector<int> prefixSum(n + 1, 0);
        int maxConsecutive = 0;
        
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + (answerKey[i - 1] == 'F');
        }
        
        auto isValidWindow = [&](int windowSize) {
            for (int i = windowSize; i <= n; i++) {
                int changes = prefixSum[i] - prefixSum[i - windowSize];
                if (changes <= k || windowSize - changes <= k) {
                    return true;
                }
            }
            return false;
        };
        
        int left = 0, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (isValidWindow(mid)) {
                maxConsecutive = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return maxConsecutive;
    }
};