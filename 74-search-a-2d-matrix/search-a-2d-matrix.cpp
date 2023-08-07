class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,h=n*m-1;
        while(l<=h)
        {
            int mid=(l+h)>>1;
            if(matrix[mid/n][mid%n]==target) return true;
            if(matrix[mid/n][mid%n]>target) h=mid-1;
            else l=mid+1;
        }
        //T.C.: **O(log(n*m))**
        return false;    
    }
};