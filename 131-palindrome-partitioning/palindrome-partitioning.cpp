class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string s)
    {
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
    void h(int idx,vector<string> &temp,string &s)
    {
        if(idx>=s.size())
        {
            ans.push_back(temp);
            return;
        }
        string str="";
        for(int i=idx;i<s.size();i++)
        {
            str+=s[i];
            if(isPalindrome(str))
            {
                temp.push_back(str);
                h(i+1,temp,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<string> temp;
        h(0,temp,s);
        return ans;
    }
};