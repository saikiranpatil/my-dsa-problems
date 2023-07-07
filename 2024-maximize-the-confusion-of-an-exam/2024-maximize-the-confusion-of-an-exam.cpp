class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int maxConsecutive = 0;
        int maxCount = 0;
        int left = 0;
        int changeCount = 0;

        for (int right = 0; right < n; right++) {
            if (answerKey[right] == 'F') {
                changeCount++;
            }

            while (changeCount > k) {
                if (answerKey[left] == 'F') {
                    changeCount--;
                }
                left++;
            }

            maxCount = max(maxCount, right - left + 1);
        }

        maxConsecutive = max(maxConsecutive, maxCount);
        maxCount = 0;
        left = 0;
        changeCount = 0;

        for (int right = 0; right < n; right++) {
            if (answerKey[right] == 'T') {
                changeCount++;
            }

            while (changeCount > k) {
                if (answerKey[left] == 'T') {
                    changeCount--;
                }
                left++;
            }

            maxCount = max(maxCount, right - left + 1);
        }

        maxConsecutive = max(maxConsecutive, maxCount);

        return maxConsecutive;
    }
};