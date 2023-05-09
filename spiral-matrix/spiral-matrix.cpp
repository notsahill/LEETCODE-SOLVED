class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ans;
        int rows=matrix.size(),count=0;
        int columns=matrix[0].size();
        int startingrow=0;
        int startingcolumn=0;
        int endingcolumn=columns-1;
        int endingrow=rows-1;
       
        while(count<rows*columns){
       //prnt starting row
        for(int i=startingcolumn;i<=endingcolumn&&count<rows*columns;i++)
        {
            ans.push_back(matrix[startingrow][i]);
            count++;
        }
        startingrow++;
        //print ending column
         for(int i=startingrow;i<=endingrow&&count<rows*columns;i++)
        {
            ans.push_back(matrix[i][endingcolumn]);
            count++;
        }
        endingcolumn--;
        //prnt ending row
        for(int i=endingcolumn;i>=startingcolumn&&count<rows*columns;i--)
        {
            ans.push_back(matrix[endingrow][i]);
            count++;
        }
        endingrow--;
        //print starting column
        for(int i=endingrow;i>=startingrow&&count<rows*columns;i--)
        {
            ans.push_back(matrix[i][startingcolumn]);
            count++;
        }
        startingcolumn++;
        }
        return ans;
    }
};