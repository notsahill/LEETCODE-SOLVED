class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int mx=0,n=points.size();
        for(int i=1;i<n;i++){
            if(points[i][0]-points[i-1][0]>mx) mx=points[i][0]-points[i-1][0];
        }
        return mx;
    }
};