class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum = nums[0]+nums[1]+nums[2];
        for(int i = 0;i< n;i++){
            int l = i+1;
            int h = n-1;
            while(l <h){
                int currsum = nums[i]+nums[l]+nums[h];
                if(abs(target- currsum) < abs(target-sum)){
                    sum = currsum;
                }
                if(currsum < target) l++;
                else h--;
            }

        }
        return sum;
    }
};