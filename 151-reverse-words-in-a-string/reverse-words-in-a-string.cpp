class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int j=0,n=s.size();
        while(j<n){
            while(j<n and s[j]==' '){
                j++;
            }
            string temp="";
            while(j<n and s[j]!=' '){
                temp+=s[j];
                j++;
            }
            if(temp.size()) words.push_back(temp);
        }
        string ans="";
        for(int i=words.size()-1;i>=0;i--){
            ans+=words[i];
            if(i!=0) ans+=" ";
        }
        return ans;
    }
};