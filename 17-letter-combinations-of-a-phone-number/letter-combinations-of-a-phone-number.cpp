class Solution {
public:
    vector<string> ans;
    
    void h(int idx,string &digits,string &temp,unordered_map<char,string> &mp)
    {
        if(idx>=digits.size())
        {
            if(temp.size()) ans.push_back(temp);
            return;
        }
        string s=mp[digits[idx]];
        for(int i=0;i<s.size();i++)
        {
            temp.push_back(s[i]);
            h(idx+1,digits,temp,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        unordered_map<char,string> mp;
        string temp="";
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        h(0,digits,temp,mp);
        return ans;
    }
};