class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4)
            return ans;
            
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
                
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for j (ensure j starts after i)
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                    
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long rem = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (target == rem) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                            
                        left++;
                        right--;
                    } else if (rem < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};