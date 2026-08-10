class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int i = 0;
        int j = nums.size() - 1;

        while (i <= j) {

            int mid = i + (j - i) / 2;

            // Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Target is greater, search right side
            if (nums[mid] < target) {
                i = mid + 1;
            }

            // Target is smaller, search left side
            else {
                j = mid - 1;
            }
        }

        // i is the correct insertion position
        return i;
    }
};