class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int i=0,j=m-1;
        while(i<n and j>=0){
            int curr=matrix[i][j];
            if(curr==target) return 1;
            if(curr>target) j--;
            else i++;
        }
        return 0;
    }
};