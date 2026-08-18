class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        int n = nums.size();

        // Generate every subarray of size k
        for (int i = 0; i <= n - k; i++) {

            // Avoid counting duplicate numbers
            // multiple times in the same window
            unordered_set<int> window;

            for (int j = i; j < i + k; j++) {
                window.insert(nums[j]);
            }

            // Count this number as appearing in this window
            for (int num : window) {
                count[num]++;
            }
        }

        int ans = -1;

        // Find the largest number appearing
        // in exactly one window
        for (auto& [num, freq] : count) {
            if (freq == 1) {
                ans = max(ans, num);
            }
        }

        return ans;
    }
};