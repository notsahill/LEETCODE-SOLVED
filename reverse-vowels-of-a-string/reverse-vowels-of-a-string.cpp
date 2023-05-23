class Solution {
public:
    bool isVowel(char val)
    {
        if(val=='a' or val=='e' or val=='i' or val=='o' or val=='u' or val=='A' or val=='E' or val=='I' or val =='O' or val=='U') return true;
        return false;
    }
    string reverseVowels(string s) 
    {
        vector<char> v;
        for(auto val:s)
        {
            if(isVowel(val)) v.push_back(val);
        }
        int idx=v.size()-1;
        for(int i=0;i<s.size();i++)
        {

            if(isVowel(s[i])) s[i]=v[idx--];
        }
        return s;
    }
};