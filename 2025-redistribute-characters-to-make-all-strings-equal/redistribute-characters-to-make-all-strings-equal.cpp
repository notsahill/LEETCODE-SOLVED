class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        map<char,int> mp;
        for(string word:words){
            for(char ch:word){
                mp[ch]++;
            }
        }
        for(auto a:mp){
            if(a.second%n!=0) return false;
        }
        return true;
    }
};