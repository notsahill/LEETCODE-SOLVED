class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        string a="",b="";
        for(auto word:word1)
        {
            for(char ch:word)
            {
                a+=ch;
            }
        }
        for(auto word:word2)
        {
            for(char ch:word)
            {
                b+=ch;
            }
        }
        return a==b;
    }
};