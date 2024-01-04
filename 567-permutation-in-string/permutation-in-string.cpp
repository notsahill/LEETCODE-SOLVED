class Solution {
public:
    bool checkIfSame(vector<int> &freq,vector<int> &mp){
        for(int i=0;i<26;i++){
            if(mp[i]!=freq[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> mp(26,0),freq(26,0);
        for(int i=0;i<s1.size();i++){
            mp[s1[i]-'a']++;
        }
        int i=0,j=0,n=s2.size();
        while(j<n){
            freq[s2[j]-'a']++;
            if(j-i+1==s1.size()){
                if(checkIfSame(freq,mp)) return true;
            }
            if(j-i+1<s1.size()) j++;
            else{
                freq[s2[i]-'a']--;
                i++,j++;
            }
        }
        return false;
    }
};