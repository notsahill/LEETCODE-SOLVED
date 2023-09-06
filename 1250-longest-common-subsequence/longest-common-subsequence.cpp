class Solution {
public:
    int h(int i,int j,string &text1,string &text2,vector<vector<int>> &dp)
    {
        if(i>=text1.size()) return 0;
        if(j>=text2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return 1+h(i+1,j+1,text1,text2,dp);
        int a=h(i+1,j,text1,text2,dp);
        int b=h(i,j+1,text1,text2,dp);
        return dp[i][j]=max(a,b);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size(),-1));
        return h(0,0,text1,text2,dp);
    }
};