class Solution {
public:
    vector<int> generaterow(int r)
    {
        long long ans=1;
        vector<int> row;
        row.push_back(ans);
        for(int col=1;col<r;col++)
        {
            ans=ans*(r-col);
            ans=ans/col;
            row.push_back(ans);
        }
        return row;
    }
    vector<vector<int>> generate(int n) 
    {
        // vector<vector<int>> ans={{1}};
        // vector<int> temp;;
        // for(int i=1;i<n;i++)
        // {
        //     for(int j=0;j<=i;j++)
        //     {
                
        //         if(j==0||j==i) temp.push_back(1);
        //         else
        //         temp.push_back(ans[i-1][j]+ans[i-1][j-1]);
        //     }
        //     ans.push_back(temp);
        //     temp.clear();
        // }
        // return ans;
        vector<vector<int>> ans;
        for(int row=1;row<=n;row++)
        {
            ans.push_back(generaterow(row));
        }
        return ans;
    }
};