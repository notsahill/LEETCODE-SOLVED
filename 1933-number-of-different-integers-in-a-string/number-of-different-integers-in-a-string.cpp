class Solution {
public:
    bool isDigit(char ch)
    {
        if(ch>='0' and ch<='9') return true;
        return false;
    }
    int numDifferentIntegers(string word) {
        set<string> st;
        for(int i=0;i<word.size();i++)
        {
            if(isDigit(word[i]))
            {
                string temp="";
                int j=i;
                while(isDigit(word[j]))
                {
                    temp+=word[j];
                    j++;
                }
                string num="";
                int k;
                for(k=0;temp[k]=='0';k++)
                {
                    
                }
                for(int x=k;x<temp.size();x++)
                {
                    num+=temp[x];
                }
                st.insert(num);
                i=j-1;
            }
        }
        return (int)st.size();
    }
};