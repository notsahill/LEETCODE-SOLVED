class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        //brute force->optimisation
        // vector<int> freq1(26,0),ans;
        // for(int i=0;i<p.size();i++)
        // {
        //     char ch=p[i];
        //     freq1[ch-'a']++;
        // }
        // int l=0,h=p.size()-1;
        // while(h<s.size())
        // {
        //     vector<int> freq2(26,0);
        //     for(int k=l;k<=h;k++)
        //     {
        //         char ch=s[k];
        //         freq2[ch-'a']++;
        //     }
        //     if(freq1==freq2) ans.push_back(l);
        //     l++;
        //     h++;
        // }
        // return ans;
        if(s.size()<p.size()) return {};
        vector<int> freq1(26,0),freq2(26,0),ans;
        for(int i=0;i<p.size();i++)
        {
            char ch1=p[i],ch2=s[i];
            freq1[ch1-'a']++;
            freq2[ch2-'a']++;
        }
        if(freq1==freq2) ans.push_back(0);
        int l=0,h=p.size();
        while(h<s.size())
        {
            freq2[s[l]-'a']--;
            freq2[s[h]-'a']++;
            if(freq1==freq2) ans.push_back(l+1);
            l++;
            h++;
        }
        return ans;
    }
};