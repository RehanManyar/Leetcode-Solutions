class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int freq = 0;

        // Boyer-Moore Voting Algorithm
        for (int num : nums) {
            if (freq == 0) {
                element = num;
            }

            if (element == num) {
                freq++;
            } else {
                freq--;
            }
        }

        // Verify whether majority element actually exists
        int count = 0;

        for (int val : nums) {
            if (val == element) {
                count++;
            }
        }

        if (count > nums.size() / 2) {
            return element;
        } else {
            return -1;
        }
    }
};