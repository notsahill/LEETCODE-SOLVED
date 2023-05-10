class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    { 
        vector<vector<int>> ans(n, vector<int>(n));
        int count=1;
        int srow=0;
        int scol=0;
        int erow=n-1;
        int ecol=n-1;
       while(count<=n*n) {
        //prnt starting row
        for(int i=scol;i<=ecol&&count<=n*n;i++)
        {
            ans[srow][i]=count;
            count++;
        }
        srow++;
        //prnt end col
        for(int i=srow;i<=erow&&count<=n*n;i++)
        {
            ans[i][ecol]=count;
            count++;
        }
        ecol--;
        //prnt end row
        for(int i=ecol;i>=scol&&count<=n*n;i--)
        {
            ans[erow][i]=count;
            count++;
        }
        erow--;
        //prnt strt col
        for(int i=erow;i>=srow&&count<=n*n;i--)
        {
            ans[i][scol]=count;
            count++;
        }
        scol++;
       }
       return ans;
    }
};