class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=n-1;
        while(i<=j){
            int mid=(i+j)>>1;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid]>arr[mid-1]) i=mid+1;
            else j=mid;
        }
        return -1;
    }
};