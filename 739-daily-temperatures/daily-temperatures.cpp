class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) 
    {
        int n=temp.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() and temp[st.top()]<=temp[i]){
                st.pop();
            }
            ans[i]= st.empty()?0:st.top()-i;
            st.push(i);
        }
        return ans;
    }
};