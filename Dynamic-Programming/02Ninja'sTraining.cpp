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