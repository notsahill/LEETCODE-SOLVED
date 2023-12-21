class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> mp;
        int i=0,n=s.size(),j=0;
        int mx=0;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()==j-i+1) mx=max(mx,j-i+1);
            while((int)mp.size()<j-i+1){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return mx;
    }
};