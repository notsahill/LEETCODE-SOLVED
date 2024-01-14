class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();){
            int u=intervals[i][0],v=intervals[i][1];
            int j=i+1;
            while(j<n and intervals[j][0]<=v){
                v=max(v,intervals[j][1]);
                j++;
            }
            i=j;
            ans.push_back({u,v});
        }
        return ans;
    }
};