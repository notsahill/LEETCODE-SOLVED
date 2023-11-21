class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int lastM = 0, lastP = 0, lastG = 0;
        int time=0;
        for(int i = 0; i < n; i++) {
           for(int j=0;j<garbage[i].size();j++)
           {
               if(garbage[i][j]=='M'){
                   lastM=i;
               }else if(garbage[i][j]=='P'){
                   lastP=i;
               }else{
                   lastG=i;
               }
               time++;
           }
        }
        vector<int> ps(n-1);
        ps[0]=travel[0];
        for(int i=1;i<n-1;i++)
        {
            ps[i]=ps[i-1]+travel[i];
        }
        if(lastM>0) time+=ps[lastM-1];
        if(lastP>0)time+=ps[lastP-1];
        if(lastG>0) time+=ps[lastG-1];
        return time;
    }
};