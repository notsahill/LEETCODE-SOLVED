class Solution {
public:
    bool closeStrings(string w1, string w2) {
        map<int,int> mp1,mp2;
        for(int a:w1){
            mp1[a]++;
        }
        for(int b:w2){
            mp2[b]++;
        }
        vector<int> v1,v2;
        for(auto a:mp1){
            int key=a.first,val=a.second;
            if(mp2[key]==val){
                mp2[key]=0;
                mp1[key]=0;
            }
            else if(mp2[key]<=0) return false;
            else v1.push_back(val);
        }
        for(auto a:mp2){
            if(a.second!=0){
                v2.push_back(a.second);
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2;
    }
};