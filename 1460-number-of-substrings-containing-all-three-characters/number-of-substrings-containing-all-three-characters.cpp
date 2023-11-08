class Solution {
public:
    int numberOfSubstrings(string s) {
        int a_idx=-1;
        int b_idx=-1;
        int c_idx=-1;
        int c=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a') a_idx=i;
            if(s[i]=='b') b_idx=i;
            if(s[i]=='c') c_idx=i;

            int mn=min(a_idx,min(b_idx,c_idx));
            c+=mn+1;
        }
        return c;
    }
};