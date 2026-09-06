class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int left = 0;
        int right = 0;
        int maxCnt = 0;
        while(right < nums.size()){
            if(nums[right] == 0){
                cnt = 0;
            }else{
                cnt++;
                maxCnt = max(maxCnt, cnt);
                left++;
                
            }
            right++;
        }
        return maxCnt;
    }
};