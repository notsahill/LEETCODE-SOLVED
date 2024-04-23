class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int> mp;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch>=65 && ch<=90){
                if(mp.find(ch)==mp.end()){
                    mp[ch]=i;
                }
            }
            else{
                mp[ch]=i;
            }
        }
        int c=0;
        for(auto x:mp){
            char ch=x.first;
            int occ=x.second;
            if((ch>=65 && ch<=90) && mp.find(ch+32)!=mp.end()){
                int socc=mp[ch+32];
                if(socc<occ) c++;
            }
        }
        return c;
    }
};