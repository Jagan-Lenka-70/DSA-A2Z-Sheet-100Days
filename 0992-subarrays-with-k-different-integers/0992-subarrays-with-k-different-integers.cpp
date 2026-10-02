class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        if (k <= 0) return 0;

        unordered_map<int, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while (freq.size() > k) {
                int value = nums[left];
                freq[value]--;
                if (freq[value] == 0) freq.erase(value);
                left++;
            }

            count += right - left + 1;
        }
        return count;
    }
};