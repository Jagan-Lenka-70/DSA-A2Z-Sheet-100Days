class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int>v(n);
        int j=0;
        for(int i=1;i<n;i+=2){
            v[i] = nums[j];
            j++;
        }
        
        for(int i=0;i<n;i+=2){
            v[i] = nums[j];
            j++;
        }
        nums = v;
    }
};