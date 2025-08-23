// Number of units of water trapped ...
class Solution {
  public:
    vector<int> getLeftMax(vector<int> &arr, int &n){
        vector<int> leftMax(n);
        leftMax[0] = arr[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], arr[i]);
        }
        return leftMax;
    }
    vector<int> getRightMax(vector<int> &arr, int &n){
        vector<int> rightMax(n);
        rightMax[0] = arr[0];
        for(int i=1; i<n; i++){
            rightMax[i] = max(rightMax[i-1], arr[i]);
        }
        return rightMax;
    }
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> leftMax = getLeftMax(arr, n);
        vector<int> rightMax = getRightMax(arr, n);
        
        int sum = 0;
        
        for(int i = 0; i<n; i++){
            int height = min(leftMax[i], rightMax[i]) - arr[i];
            sum += height;
        }
        
        return sum;
    }
};