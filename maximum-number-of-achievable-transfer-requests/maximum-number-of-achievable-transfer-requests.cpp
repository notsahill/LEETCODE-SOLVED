class Solution {
public:
    int ans=INT_MIN;
    void helper(int idx,vector<vector<int>> &requests,vector<int> buildings,int cnt)
    {
        if(idx==requests.size()) 
        {
            bool f=0;
            for(auto a:buildings) if(a!=0) f=1;
            if(!f) ans=max(ans,cnt);
            return;
        }
        int from=requests[idx][0];
        int to=requests[idx][1];
        //fulfill request
        buildings[from]-=1;
        buildings[to]+=1;
        helper(idx+1,requests,buildings,cnt+1); //aur aage check kiya
        //backtrack kiya
        buildings[to]-=1;
        buildings[from]+=1;
        helper(idx+1,requests,buildings,cnt); //aur aage explore kiya

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> buildings(n,0);
        helper(0,requests,buildings,0);
        return ans;
    }
};