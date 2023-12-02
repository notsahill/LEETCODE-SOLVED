class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> mp;
        for(char ch:chars)
        {
            mp[ch]++;
        }
        int ans=0;
        for(auto word:words)
        {
            map<char,int> mp1;
            for(char ch:word)
            {
                mp1[ch]++;
            }
            bool f=1;
            for(auto [a,b]:mp1)
            {
                if(b>mp[a]) 
                {
                    f=0;
                    break;
                }
            }  
            if(f) ans+=word.size();       
        }
        return ans;
    }
};