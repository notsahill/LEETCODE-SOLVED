class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) 
    {
        int dy=(c[1][1]-c[0][1]);
        int dx=(c[1][0]-c[0][0]);
        for(int i=1;i<c.size();i++)
        {
            int y=(c[i][1]-c[i-1][1]);
            int x=(c[i][0]-c[i-1][0]);
            if(x*dy != y*dx) return 0;
        }
        return 1;
    }
};