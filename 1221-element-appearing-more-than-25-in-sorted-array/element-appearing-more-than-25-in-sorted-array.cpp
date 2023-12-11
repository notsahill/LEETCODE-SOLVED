class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int i=0,j=0,n=arr.size();
        int diff=4-n%4;
        int mx=(n+diff)/4;
        while(j<n){
            while(j<n and arr[j]==arr[i]){
                j++;
            }
            if(j-i+1>mx) return arr[i];
            i=j;
        }
        return 0;
    }
};