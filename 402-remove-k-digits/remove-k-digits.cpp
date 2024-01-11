class Solution {
public:
    string removeKdigits(string s, int k) 
    {
        stack<int> st;
        for(char ch:s){
            while(k>0 and st.size() and st.top()>ch) {
                k--;
                st.pop();
            }
            st.push(ch);
        }
        while(st.size() and k>0) {
            k--;
            st.pop();
        }
        string ans="";
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        while(ans.size() && ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans==""?"0":ans;
    }
};