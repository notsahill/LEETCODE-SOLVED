class Solution {
public:
    int dp[2001][4];
    bool isPalindrome(int i,int j,string &s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }

    int h(int idx,int cuts_made,string &s)
    {
        
        if(idx>=s.size())
        {
            return cuts_made==2;
        }
        if(cuts_made>=2) return isPalindrome(idx,s.size()-1,s);
        if(dp[idx][cuts_made]!=-1) return dp[idx][cuts_made];
        int ans=0;
        for(int i=idx;i<s.size()-1;i++)
        {
            if(isPalindrome(idx,i,s)) //possible partioning
            {
                ans|=h(i+1,cuts_made+1,s); //do partitioning
            }
        }
        return dp[idx][cuts_made]=ans;
    }

    bool checkPartitioning(string s) {
        memset(dp,-1,sizeof(dp));
        return h(0,0,s);
    }
};