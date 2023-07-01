class Solution {
public:
    int min_cookies=INT_MAX;
    void helper(int idx,vector<int> &assign,vector<int> &cookies,int k)
    {
        if(idx==cookies.size())
        {
            int maxi=*max_element(assign.begin(),assign.end());
            min_cookies=min(min_cookies,maxi);
            return;
        }
        int to_assign=cookies[idx];
        for(int i=0;i<k;i++)
        {
            assign[i]+=to_assign;
            helper(idx+1,assign,cookies,k);
            assign[i]-=to_assign;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) 
    {
        vector<int> assign(k,0);
        helper(0,assign,cookies,k);
        return min_cookies;
    }
};