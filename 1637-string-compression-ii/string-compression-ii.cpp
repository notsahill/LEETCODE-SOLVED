int dp[101][101][27][101];
class Solution {
public:
    int h(int i,int k,int prev,int prev_freq,string &s){
        if(k<0) return 1e9;
        if(i>=s.size()) return 0;
        if(dp[i][k][prev][prev_freq]!=-1) return dp[i][k][prev][prev_freq];
        int del_i=h(i+1,k-1,prev,prev_freq,s);
        int take_i=1e9,c=0;
        if(prev!=s[i]-'a') take_i=1+h(i+1,k,s[i]-'a',1,s);
        else {
            if(prev_freq==1 or prev_freq==9 or prev_freq==99) c=1;
            take_i= c+h(i+1,k,prev,prev_freq+1,s);
        }
        return dp[i][k][prev][prev_freq]=min(take_i,del_i);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return h(0,k,26,0,s);
    }
};