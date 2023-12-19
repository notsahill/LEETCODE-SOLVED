class Solution {
public:
    int findAverage(int i1,int j1,vector<vector<int>> &img){
        int n=img[0].size(),m=img.size();
        int sum=0,c=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int ni=i1+i;
                int nj=j1+j;
                if(ni<0 or ni>=m) continue;
                if(nj<0 or nj>=n) continue;
                sum+=img[ni][nj];
                c++;
            }
        }
        return sum/c;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img[0].size(),m=img.size();
        vector<vector<int>> ans(m , vector<int> (n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=findAverage(i,j,img);
            }
        }
        return ans;
    }
};