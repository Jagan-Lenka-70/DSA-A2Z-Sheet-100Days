class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> seen;
        long long sum = 0;
        long long maxSum = 0;
        int left = 0;
        int right = k-1;
        for(int i = left;i <= right;i++){
            seen[nums[i]]++;
            sum+=nums[i];
        }
        while(right < nums.size()){
            if(seen.size() == k) maxSum = max(sum,maxSum);

            sum -= nums[left];
            seen[nums[left]]--;
            if(seen[nums[left]] == 0) seen.erase(nums[left]);
            left++;
            right++;
            if(right < nums.size()){
                sum += nums[right];
                seen[nums[right]]++;
            }
        }
        return maxSum;
    }
};