class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int mx=0;
        for(int i=0;i<n-1;i++){
            int zc=0;
            for(int j=0;j<=i;j++){
                if(s[j]=='0') zc++;
            }
            int oc=0;
            for(int j=i+1;j<n;j++){
                if(s[j]=='1') oc++;
            }
            mx=max(mx,oc+zc);
        }
        return mx;
    }
};