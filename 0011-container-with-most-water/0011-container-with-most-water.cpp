class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxA = INT_MIN;
        while(left < right){

            int maxC = min(height[left],height[right])*(right-left);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
            maxA = max(maxC,maxA);
        }
        return maxA;
    }
};