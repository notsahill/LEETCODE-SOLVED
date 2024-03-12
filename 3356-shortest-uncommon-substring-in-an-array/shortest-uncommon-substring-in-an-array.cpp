class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        unordered_map<int,unordered_set<string>> mp;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            string str=arr[i];
            for(int j=0;j<str.size();j++){
                string temp="";
                for(int k=j;k<str.size();k++){
                    temp+=str[k];
                    mp[i].insert(temp);
                }
            }
        }
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            string ithPlaceString="";
            int mnLen=1e9;
            for(string curr:mp[i]){
                bool f=0;
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    if(mp[j].find(curr)!=mp[j].end()){
                        f=1;
                        break;
                    }
                }
                if(!f){//curr is not present in jth idx substrings
                    if(curr.size()<mnLen){
                        mnLen=curr.size();
                        ithPlaceString=curr;
                    }
                    else if(curr.size()==mnLen && curr<ithPlaceString){
                        ithPlaceString=curr;
                    }
                }
            }
            ans[i]=ithPlaceString;
        }
        return ans;
    }
};