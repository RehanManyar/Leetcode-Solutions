class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Calculate prefix sum
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // Start with the total sum
        int ans = stones[n - 1];

        // Try every possible prefix
        for (int i = n - 2; i >= 1; i--) {
            ans = max(ans, stones[i] - ans);
        }

        return ans;
    }
};