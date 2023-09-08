class Solution {
public:
    bool isPalindrome(string &s)
    {
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }

    int h(int idx,string &s,vector<int> &dp)
    {
        if(idx>=s.size()) return 0;
        int ans=INT_MAX;
        string temp="";
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<s.size();i++)
        {
            temp+=s[i];
            if(isPalindrome(temp)) //partition possible
            {
                int do_partition=1+h(i+1,s,dp);
                ans=min(ans,do_partition);
            }
        }
        return dp[idx]=ans;
    }

    int minCut(string s) {
        vector<int> dp(s.size()+1,-1);
        return h(0,s,dp)-1;
    }
};