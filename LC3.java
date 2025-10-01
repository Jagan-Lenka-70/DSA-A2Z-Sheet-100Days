518. Water Bottles
Solved
Easy
Topics
premium lock icon
Companies
Hint
There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

 

Example 1:


Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.
Example 2:


Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
Number of water bottles you can drink: 15 + 3 + 1 = 19.
 

Constraints:

1 <= numBottles <= 100
2 <= numExchange <= 100
 
Intuition
The total number of bottles would be reduced by number of exchange bottle rate after the full bottles are empty meaning if full = 10 and the exchange =2 it means that you will be 5 bottles in the next round.

Approach
Get the multipling factor after the bottles are empty meaning divide the total bottle by the exchange rate that will give you the number of bottles you will get after the exchange. also do find the remainder if the totla bottle is not a fcator of the exchange number like totla =15 and exchange =2 so in this 1 bottle will not be exchanges. Now the initial count was 15 after exchange we get 7 bottles and 1 bottle was not exchanged so total full bottles till this stage is = 15+7 =22 and empty bottles after content of those 7 bootles are empty is 8(7(full)+ 1(empty from last time)) .
Now this will give me 4 new full bottles then 2 new bottle and finally 1

Full = 15
exchange =2

count =15(till this point)
after 1st exchange
full = 7(15/2)
left empty bottle which was not exchanged = 1(15%2)

now count = 15+7
empty bottle = 7+1

and so on.

Complexity
Time complexity:
O(n)

Space complexity:
O(1)

Code
class Solution {
    public int numWaterBottles(int f, int e) {
        int count=f;
        int extra =0;
        
        while(f>1 ){
            extra = f%e;
            f = f/e;
            count += f;
            if(f+extra>=e){
                f += extra;
            }
        }
        return count;
    }
}
