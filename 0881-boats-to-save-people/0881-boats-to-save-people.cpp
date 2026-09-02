class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;      // lightest person got paired, move left forward
            }
            right--;         // heaviest person is always handled (paired or alone)
            boats++;          // one boat used this round, regardless of branch
        }
        
        return boats;
    }
};