class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int target_value = 0;
        for(int value : nums) {
            target_value ^= value;
        }
        return target_value;
    }
};