class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) 
    {
        unordered_map<string,int> m;
        int c=0;
        for(auto str:words)
        {
            m[str]++;
        }
        for(string s:words)
        {
            if(m[s]<1) continue;
            string str=s;
            reverse(s.begin(),s.end());
            string rev=s;
            if(rev==str) continue;
            if(m[rev]>0)
            {
                c++;
                m[rev]--;
                m[str]--;
            }
        }
        return c;
    }
};