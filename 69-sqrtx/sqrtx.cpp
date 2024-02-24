class Solution {
public:
    int mySqrt(int x) {
        unsigned long long int l=0,h=x;
        int ans;
        while(l<=h){
            unsigned long long int mid=(h-l)/2+l;
            if(mid*mid>x){
                h=mid-1;
            }else{
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
};