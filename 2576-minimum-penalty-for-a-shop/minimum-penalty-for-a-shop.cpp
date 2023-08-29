class Solution {
public:
    int bestClosingTime(string c) {
        int n=c.size();
        vector<int> NO_until_now(n+1);
        NO_until_now[0]= c[0]=='N';
        for(int i=1;i<=n;i++)
        {
            if(i==n) NO_until_now[i] =NO_until_now[i-1];
            else
            {
                if(c[i]=='N') NO_until_now[i]=NO_until_now[i-1]+1;
                else NO_until_now[i]=NO_until_now[i-1];
            }
        }
        vector<int> YES_ahead_of_now(n+1,0); //including that pos
        YES_ahead_of_now[n-1]= c[n-1]=='Y';
        for(int i=n-2;i>=0;i--)
        {
            if(c[i]=='Y') YES_ahead_of_now[i]=YES_ahead_of_now[i+1]+1;
            else YES_ahead_of_now[i]=YES_ahead_of_now[i+1];
        }
        int ans=0,mn=YES_ahead_of_now[0];
        for(int i=1;i<=n;i++)
        {
            int curr=YES_ahead_of_now[i]+NO_until_now[i-1];
            if(curr<mn)
            {
                mn=curr;
                ans=i;
            }
        }
        return ans;
    }
};