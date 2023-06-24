class Solution {
public:
    int dp[1000][26][26];
    int helper(vector<string>& words,int s,int e,int i)
    {
        if(i>=words.size()) return 0;
        int mn=INT_MAX;
        if(dp[i][s][e]!=-1) return dp[i][s][e];
        mn=min(mn,helper(words,s,words[i].back()-'a',i+1)+(int)words[i].size()-(e+'a'==words[i][0]));
        mn=min(mn,helper(words,words[i][0]-'a',e,i+1)+(int)(words[i].size())-(s+'a'==words[i].back()));
        return dp[i][s][e]=mn;
    }
    int minimizeConcatenatedLength(vector<string>& words) 
    {
        memset(dp,-1,sizeof(dp));
        return helper(words,words[0][0]-'a',words[0].back()-'a',1)+words[0].size();
    }
};