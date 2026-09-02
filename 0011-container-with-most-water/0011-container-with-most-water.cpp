class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxValue = INT_MIN;
        while (left <= right) {
            int sum = min(height[left], height[right]) * (right - left);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
            maxValue = max(maxValue,sum);
        }
        return maxValue;
    }
};