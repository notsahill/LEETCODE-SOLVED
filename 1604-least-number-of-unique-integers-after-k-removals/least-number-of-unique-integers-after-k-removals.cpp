class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<vector<int>> v;
        for(auto a:mp){
            v.push_back({a.first,a.second});
        }
        sort(v.begin(),v.end(),cmp);
        int ans=v.size();
        for(int i=0;i<v.size();i++){
            int occ=v[i][1];
            if(occ<=k){
                k-=occ;
                ans--;
            }
            else break;
        }
        return ans;
    }
};