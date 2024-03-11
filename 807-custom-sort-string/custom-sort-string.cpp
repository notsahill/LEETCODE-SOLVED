class Solution {
public:
    string customSortString(string order, string s) {
        //giving maximum preference to charcters that appear first in order
        vector<int> preference(26,0);
        int x=26;
        for(char ch:order){
            preference[ch-'a']=x;
            x--;
        }

        //apply bubble sort
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(preference[s[j]-'a']>preference[s[i]-'a']){
                    swap(s[i],s[j]);
                }
            }
        }
        return s;
    }
};