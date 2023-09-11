class Solution {
public:
    int h(int i,int j,string &w1,string &w2,vector<vector<int>> &dp)
    {
        if(i>=w1.size()) return w2.size()-j;
        if(j>=w2.size()) return w1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]) return h(i+1,j+1,w1,w2,dp);
        int x=h(i+1,j,w1,w2,dp);
        int y=h(i,j+1,w1,w2,dp);
        return dp[i][j]=min(x,y)+1;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1,-1));
        return h(0,0,word1,word2,dp);
    }
};