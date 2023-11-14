class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int c=0;
        unordered_set<char> st;
        for(char a:s) st.insert(a);
        for(char a:st)
        {
            int i=-1,j=0;
            for(int idx=0;idx<s.size();idx++)
            {
                if(s[idx]==a)
                {
                    if(i==-1) i=idx;
                    j=idx;        
                }
            }
            set<char> temp;
            for(int idx=i+1;idx<j;idx++)
            {
                temp.insert(s[idx]);
            }        
            c+=(int)temp.size();
        }
        return c;
    }
};