class Solution {
public:
    string minWindow(string s, string t) 
    {
        int reqd=t.size(),i=0,j=0,start_i=0,n=s.size(),mn=INT_MAX;
        unordered_map<char,int> mp;
        for(auto a:t)
        {
            mp[a]++;
        }
        while(j<n)
        {
            char ch=s[j];
            if(mp[ch]>0)
            {
                reqd--;
            }
            mp[ch]--;
            //shrink shrink
            while(reqd==0)
            {
                int sz=j-i+1;
                if(sz<mn)
                {
                    mn=sz;
                    start_i=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) reqd++;
                i++;
            }
            j++;
        }
        if(mn==INT_MAX) return "";
        return s.substr(start_i,mn);
    }
};