class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int CurMin = nums[0];
        int CurMax = nums[0];
        int ans = nums[0];
        for(int i = 1;i < n;i++){
            if(nums[i]<0) swap(CurMin,CurMax);
            CurMin = min(nums[i],CurMin*nums[i]);
            CurMax =max(nums[i],CurMax*nums[i]);
            ans = max(ans,CurMax);
        }
        return ans;
    }
};