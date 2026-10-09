class Solution {
private:
    int calculateScore(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        int prev = 0;
        int prevnext = 0;
        
        for (int i = 0; i < n; i++) {
            // Check if any of the previous two turns had 10 pins
            if (prev >= 10 || prevnext >= 10) {
                sum += arr[i] * 2;
            } else {
                sum += arr[i];
            }
            
            // Shift history: current becomes prev, prev becomes prevnext
            prevnext = prev;
            prev = arr[i];
        }
        return sum;
    }

public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = calculateScore(player1);
        int score2 = calculateScore(player2);
        
        if (score1 > score2) return 1;
        if (score2 > score1) return 2;
        return 0;
    }
};