class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
       int right = k;
       long long sum = 0;
       for(int i = 0;i < right;i++){
        sum += nums[i];
       }
       long long maxSum = sum;
        for(int right = k;right<nums.size();right++){
            sum +=nums[right] - nums[right - k];
            maxSum = max(sum,maxSum);
        }
        return (double)maxSum/k;
        
    }
};