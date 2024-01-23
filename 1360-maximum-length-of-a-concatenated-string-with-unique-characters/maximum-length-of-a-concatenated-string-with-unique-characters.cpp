class Solution {
public:
    int mx=0;
    bool isGood(string &str){
        unordered_set<int> s(str.begin(),str.end());
        return (int)s.size()==(int)str.size();
    }
    void h(int idx,string &temp,vector<string> &arr){
        if(idx>=arr.size()) {
            if(isGood(temp)){
                int sz=(int)temp.size();
                mx=max(mx,sz);
            }
            return;
        }
        string temp2=temp+arr[idx];
        if(isGood(temp2)){
            temp+=arr[idx];
            h(idx+1,temp,arr);
            for(int i=0;i<arr[idx].size();i++) temp.pop_back();
        }
        h(idx+1,temp,arr);
        
    }
    int maxLength(vector<string>& arr) {
        string temp="";
        h(0,temp,arr);
        return mx;
    }
};