class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int mx=-1;
        map<int,int> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                mx=max(mx,i-mp[s[i]]-1);
            }
            else mp[s[i]]=i;
        }
        return mx;
    }
};