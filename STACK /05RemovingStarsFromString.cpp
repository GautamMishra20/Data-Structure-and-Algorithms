class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '*'){
                st.pop();
            }    
            else if(s[i] != '*'){
                st.push(s[i]);
            }
        }

        string ans = "";
        if(st.empty()){
            return ans;
        }
        else{
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            reverse(begin(ans) , end(ans));
        }

        return ans;

        
    }
};