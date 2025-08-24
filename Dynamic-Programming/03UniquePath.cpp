// Recursion technique;
class Solution {
public:
    int recursion(int i, int j){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        int up = recursion(i-1, j);
        int left = recursion(i, j-1);

        return up+left;
    }
    int uniquePaths(int m, int n) {
        return recursion(m-1, n-1);
    }
};