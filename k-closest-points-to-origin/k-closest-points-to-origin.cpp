class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<pair<int,pair<int,int>>> v;
        vector<vector<int>> ans;
        for(auto a:points)
        {
            int i=a[0],j=a[1];
            int d=i*i+j*j;
            v.push_back({d,{i,j}});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<k;i++)
        {
            int x=v[i].second.first;
            int y=v[i].second.second;
            ans.push_back({x,y});
        }
        return ans;
    }
};