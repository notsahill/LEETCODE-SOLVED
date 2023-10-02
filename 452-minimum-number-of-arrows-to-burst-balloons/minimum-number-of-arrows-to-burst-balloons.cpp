class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int from=points[0][0],to=points[0][1];
        int c=1;
        for(int i=1;i<points.size();i++)
        {
            int curr_from= points[i][0];
            int curr_to=points[i][1];
            if(curr_from<=to)
            {
                to=min(to,curr_to);
            }
            else
            {
                from=curr_from;
                to=curr_to;
                c++;
            }
        }
        return c;
    }
};