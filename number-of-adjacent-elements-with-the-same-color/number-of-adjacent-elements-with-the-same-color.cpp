class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) 
    {
        vector<int> color(n,0),ans;
        int c=0;
        for(int i=0;i<queries.size();i++)
        {
            int idx=queries[i][0];
            int nclr=queries[i][1];
            int left= idx-1<0 ?0:color[idx-1];
            int right=idx+1==n?0:color[idx+1];
            if(color[idx]!=0&&color[idx]==left) c--;
            if(color[idx]!=0&&color[idx]==right) c--;
            color[idx]=nclr;
            if(color[idx]==left) c++;
            if(color[idx]==right) c++;
            ans.push_back(c);
        }
        return ans;
    }
};