/*
Recursion Technique:-
*/
class Solution {
  public:
    int recursion(int day, int last, vector<vector<int>>& arr){
        int n = arr.size();
        if(day==0){
            int maxi = 0;
            for(int i = 0; i<n; i++){
                if(i != last) {
                    maxi = max(maxi, arr[0][i]);
                }
            }
            return maxi;
        }
        
        int maxi = 0; 
        for(int i=0; i<n; i++){
            if(i != last){
                int points = arr[day][i] + recursion(day-1, i, arr);
                maxi = max(maxi, points);
            }
        }
        return maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        return recursion(n-1, n, arr);
        
    }
};



// Memoization
class Solution {
  public:
    int recursion(int day, int last, vector<vector<int>>& arr , vector<vector<int>> &dp){
        // int n = arr.size();
        if(day==0){
            int maxi = 0;
            for(int i = 0; i<3; i++){
                if(i != last) {
                    maxi = max(maxi, arr[0][i]);
                }
            }
            return maxi;
        }
        if(dp[day][last] != -1) return dp[day][last];
        int maxi = 0; 
        for(int i=0; i<3; i++){
            if(i != last){
                int points = arr[day][i] + recursion(day-1, i, arr,dp);
                maxi = max(maxi, points);
            }
        }
        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (4, -1));
        return recursion(n-1, 3, arr, dp);
        
    }
};