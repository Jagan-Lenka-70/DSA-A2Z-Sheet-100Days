class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        while (n >= i) {   // enough coins to fill row i
            n -= i;
            i++;
        }
        return i - 1;      // last full row
    }
};