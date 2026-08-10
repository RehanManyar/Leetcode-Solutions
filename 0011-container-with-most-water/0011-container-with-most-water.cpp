class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            // Calculate width
            int width = right - left;
            // Water level is limited by shorter line
            int waterHeight = min(height[left], height[right]);
            // Calculate current area
            int currentArea = width * waterHeight;
            // Update maximum
            maxWater = max(maxWater, currentArea);
            // Move the pointer with smaller height
            height[left] < height[right] ? left++ : right--;
        }

        return maxWater;
    }
};