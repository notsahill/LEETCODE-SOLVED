class Solution {
public:
    bool allZero(vector<int> &freq)
    {
        for(auto a:freq)
        {
            if(a!=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) 
    {
        if(p.size()>s.size()) return {};
        int n=s.size(),k=p.size();
        vector<int> freq(26,0),ans;
        for(auto a:p)
        {
            freq[a-'a']++;
        }
        for(int i=0;i<k;i++)
        {
            freq[s[i]-'a']--;
        }
        if(allZero(freq)) ans.push_back(0);
        int i=0,j=k;
        while(j<n)
        {
            freq[s[i]-'a']++;
            i++;
            freq[s[j]-'a']--;
            if(allZero(freq)) ans.push_back(i);
            j++;
        }
        return ans;
    }
};