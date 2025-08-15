class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n){
        vector<int> NSL(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            if(st.empty()){
                NSL[i] = -1;
                // st.push(i);
            }
            else{
                while(!st.empty() && arr[i] <= arr[st.top()]){
                    st.pop();
                }
                NSL[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return NSL;
    }

    vector<int> getNSR(vector<int>& arr, int n){
        vector<int> NSR(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                NSR[i] = n;
                // st.push(i);
            }
            else{
                while(!st.empty() && arr[i] < arr[st.top()]){
                    st.pop();
                }
                NSR[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return NSR;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr,n);
        vector<int> NSR = getNSR(arr,n);
        long long sum = 0;
        int m = 1e9 + 7;
        for(int i=0; i<n; i++){
            int ls = i - NSL[i];
            int  rs = NSR[i] - i;
            long long totalWays = ls*rs;
            long long totalSum = arr[i]*totalWays;
            sum = (sum+totalSum)%m;
        }
        return sum;
    }
};