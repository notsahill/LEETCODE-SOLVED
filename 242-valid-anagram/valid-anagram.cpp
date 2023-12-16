class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return 0;
        vector<int> mp(26,0);
        for(char ch:s){
            mp[ch-'a']++;
        }
        for(char ch:t){
            mp[ch-'a']--;
        }
        for(int a:mp){
            if(a!=0) return 0;
        }
        return 1;
    }
};