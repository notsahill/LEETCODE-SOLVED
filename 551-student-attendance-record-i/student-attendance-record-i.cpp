class Solution {
public:
    bool checkRecord(string s) {
        int absent_count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='A') absent_count++;
            if(i<s.size()-2 and s[i]=='L' and s[i+1]=='L' and s[i+2]=='L') return false;
        }
        return absent_count<2;
    }
};