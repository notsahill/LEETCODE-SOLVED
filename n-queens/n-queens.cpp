class Solution {
public:
    bool isSafe(int i,int j,vector<string> &board,int n)
    {
        int oi=i,oj=j;
        while(i>=0 and j>=0)
        {
            if(board[i--][j--]=='Q') return false;
        }
        i=oi;
        j=oj;
        while(j>=0)
        {
            if(board[i][j--]=='Q') return false;
        }
        i=oi;
        j=oj;
        while(i<n and j>=0)
        {
            if(board[i++][j--]=='Q') return false;
        }
        return true;
    }
    void solve(int j,vector<string> &board,vector<vector<string>> &ans,int n)
    {
        if(j==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(isSafe(i,j,board,n))
            {
                board[i][j]='Q';
                solve(j+1,board,ans,n);
                board[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};