Majority Element-I

Given an integer array nums of size n, return the majority element of the array.



The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.


Examples:
Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]

Output: 7

Explanation:

The number 7 appears 5 times in the 9 sized array

Input: nums = [1, 1, 1, 2, 1, 2]

Output: 1

Explanation:

The number 1 appears 4 times in the 6 sized arrayimport java.util.*;

Intuition 
Naive way is to count the occurrences of each element. The element which will have count greater than half the array size will be the majority element.

Approach 
Iterate in the array to select the elements of the array one by one. Now, for each element, run another loop and count its occurrence in the given array.
If any element occurs more than the floor of (N/2), simply return it.

CODE:
class Solution {
    // Function to find the majority element in an array
    public int majorityElement(int[] nums) {
        
        // Size of the given array
        int n = nums.length;
        
        // Iterate through each element of the array
        for (int i = 0; i < n; i++) {
            
            // Counter to count occurrences of nums[i]
            int cnt = 0; 
            
            // Count the frequency of nums[i] in the array
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }
            
            // Check if frequency of nums[i] is greater than n/2
            if (cnt > (n / 2)) {
                // Return the majority element
                return nums[i]; 
            }
        }
        
        // Return -1 if no majority element is found
        return -1; 
    }

    public static void main(String[] args) {
        int[] arr = {2, 2, 1, 1, 1, 2, 2};
        
        // Create an instance of Solution class
        Solution sol = new Solution();
 
        int ans = sol.majorityElement(arr);
        
        // Print the majority element found
        System.out.println("The majority element is: " + ans);
    }
}
