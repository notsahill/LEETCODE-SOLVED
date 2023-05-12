class Solution {
public:
    bool canJump(vector<int>& arr) {
        int end=0,maxi=0,n=arr.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,i+arr[i]);
            if(i==end){
                end=maxi;
            }
        }
        return end>=n-1;
    }
};