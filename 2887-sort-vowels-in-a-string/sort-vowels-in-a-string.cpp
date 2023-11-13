class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u') return true;
        if(ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U') return true;
        return false;
    }
    string sortVowels(string str) {
        string s=str;
        vector<char> vowels;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(isVowel(ch))
            {
                vowels.push_back(ch);
                s[i]='*';
            }
        }
        sort(vowels.begin(),vowels.end());
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='*') continue;
            s[i]=vowels[j++];
            if(j==vowels.size()) break;
        }
        return s;
    }
};