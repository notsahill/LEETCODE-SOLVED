class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            int u=intervals[i][0];
            int v=intervals[i][1];
            if(ans.size() and ans.back()[1]>=v)
            {
                continue;
            }
            for(int j=i+1;j<n;j++)
            {
                int start=intervals[j][0];
                int end=intervals[j][1];
                if(start<=v)
                {
                    v=max(v,end);
                }
                else break;
            }
            ans.push_back({u,v});
        }
        return ans;
        //T.C.: O(n*log(n)) + 2*O(n)
        //if we want to not alter the given data toh we'll use O(n) extra space as well
    }
};