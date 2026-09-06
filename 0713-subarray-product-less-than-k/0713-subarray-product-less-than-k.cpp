class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;              // no positive product can be < 1
        long long product = 1;
        int cnt = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            while (product >= k) {         // shrink until valid — can be more than once
                product /= nums[left++];
            }
            cnt += right - left + 1;       // ALL subarrays ending at right
        }
        return cnt;
    }
};