class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minValue = nums[0];
        int maxDiff = -1;

        for (int i = 1; i < nums.size(); i++) {

            // If current value is greater than the minimum value,
            // we have a valid pair: nums[i] > minValue
            if (nums[i] > minValue) {
                // Calculate the difference and keep the maximum one
                maxDiff = max(maxDiff, nums[i] - minValue);
            }
            // Update the minimum value for future elements
            minValue = min(minValue, nums[i]);
        }
        return maxDiff;
    }
};