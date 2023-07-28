class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.size(),i=0,j=0,mx=INT_MIN;
        unordered_map<int,int> mp;
        while(j<n)
        {
            mp[s[j]]++;
            if((int)mp.size()==j-i+1)
            {
                mx=max(mx,j-i+1);
            }
            while((int)mp.size()<j-i+1)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        if(mx==INT_MIN) return 0;
        return mx;
    }
};