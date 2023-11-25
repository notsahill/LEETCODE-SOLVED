class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBar, vector<int>& vBar) {
        sort(hBar.begin(),hBar.end());
        sort(vBar.begin(),vBar.end());
        int h=1,v=1,hmx=1,vmx=1;
        for(int i=1;i<hBar.size();i++)
        {
            if(hBar[i]==hBar[i-1]+1) h++;
            else{ 
                h=1;
            }
            hmx=max(hmx,h);
        }
        for(int i=1;i<vBar.size();i++)
        {
            if(vBar[i]==vBar[i-1]+1) v++;
            else {
                v=1;
            }
            vmx=max(vmx,v);
        }
        int side= 1+min(hmx,vmx);
        return side*side;
    }
};