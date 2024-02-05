class Solution {
public:
    int firstUniqChar(string str) 
    {
        int n=str.size();
        unordered_map<char,int> um;
        for(auto a:str)
        {
            um[a]++;
        }
        for(int i=0;i<n;i++)
        {
            if(um[str[i]]==1) return i;
        }
        return -1;
    }
};