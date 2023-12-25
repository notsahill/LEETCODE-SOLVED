class Solution {
public:
    int dp[102];
    int h(int idx,string &s){
        if(idx>=s.size()) return 1;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=h(idx+1,s);
        if(idx+1<s.size() and (s[idx]=='1' or (s[idx]=='2' && s[idx+1]<='6'))){
            ans+=h(idx+2,s);
        }
        return dp[idx]=ans;
    }

    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return h(0,s);
    }
};