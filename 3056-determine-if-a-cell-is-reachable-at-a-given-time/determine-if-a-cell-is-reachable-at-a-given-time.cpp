class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int h=abs(fy-sy),v=abs(fx-sx);
        if(h==0 and v==0 and t==1) return 0;
        int mn=max(h,v);
        if(t<mn) return 0;
        return 1;
    }
};