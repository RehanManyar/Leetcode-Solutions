class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int numOne = 0; numOne < nums.size(); numOne++){
            for(int numPluse = numOne+1; numPluse < nums.size(); numPluse++){
                if ((nums[numOne]+nums[numPluse]) == target){
                    return {numOne , numPluse};
                }
            }
        }
        return {};
    }
};