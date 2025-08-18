class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        int prev = 1;
        int prev2 = 1;
        for(int i = 2; i<=n; i++){
            int curri = prev2 + prev;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};