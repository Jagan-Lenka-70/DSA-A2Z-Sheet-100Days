class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = (long long)nums[i] - nums[j];
                int cnt = dp[j].count(d) ? dp[j][d] : 0;
                ans += cnt;
                dp[i][d] += cnt + 1;
            }
        }
        return ans;
    }
};