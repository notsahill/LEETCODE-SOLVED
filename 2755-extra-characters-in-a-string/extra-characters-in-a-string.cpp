class Solution {
public:
    int h(int idx,string &s,set<string> &st,vector<int> &dp)
    {
        if(idx>=s.size()) return 0;
        int mn=INT_MAX;
        string temp="";
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<s.size();i++)
        {
            int curr=0;
            temp+=s[i];
            if(!st.count(temp))
            {
                curr+=(int)temp.size();
            }
            curr+=h(i+1,s,st,dp);
            mn=min(mn,curr);
        }

        return dp[idx]=mn;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st;
        for(string str:dictionary)
        {
            st.insert(str);
        }
        vector<int> dp(s.size()+1,-1);
        return h(0,s,st,dp);
    }
};