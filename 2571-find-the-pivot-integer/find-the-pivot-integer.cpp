class Solution {
public:
    int pivotInteger(int n) {
        vector<int> ps(n+1,0),ss(n+1,0);
        ps[1]=1,ss[n]=n;
        for(int i=2;i<=n;i++){
            ps[i]=ps[i-1]+i;
        }
        for(int i=n-1;i>=1;i--){
            ss[i]=ss[i+1]+i;
        }
        for(int i=1;i<=n;i++){
            if(ps[i]==ss[i]) return i;
        }
        return -1;
    }
};