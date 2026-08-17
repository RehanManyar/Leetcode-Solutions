class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // dp[i][j] = maximum score from subarray i...j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // mx[i][j] = maximum value of
        // dp[i][k] + sum(i...k), for i <= k <= j
        vector<vector<int>> mx(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            mx[i][i] = stoneValue[i];
        }

        // Fix the right boundary
        for (int j = 1; j < n; j++) {

            int mid = j;
            int sum = stoneValue[j];
            int rightSum = 0;

            // Move left boundary
            for (int i = j - 1; i >= 0; i--) {

                sum += stoneValue[i];

                // Find the point where
                // left sum becomes >= right sum
                while (mid > i &&
                       (rightSum + stoneValue[mid]) * 2 <= sum) {

                    rightSum += stoneValue[mid];
                    mid--;
                }

                // Equal sums
                if (rightSum * 2 == sum) {
                    dp[i][j] = mx[i][mid];
                }

                // Left side is smaller
                if (mid != i) {
                    dp[i][j] = max(
                        dp[i][j],
                        mx[i][mid - 1]
                    );
                }

                // Right side is smaller
                if (mid != j) {
                    dp[i][j] = max(
                        dp[i][j],
                        mx[j][mid + 1]
                    );
                }

                // Update helper tables
                mx[i][j] = max(
                    mx[i][j - 1],
                    dp[i][j] + sum
                );

                mx[j][i] = max(
                    mx[j][i + 1],
                    dp[i][j] + sum
                );
            }
        }

        return dp[0][n - 1];
    }
};