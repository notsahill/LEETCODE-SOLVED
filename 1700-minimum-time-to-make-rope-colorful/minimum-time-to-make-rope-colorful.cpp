class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int ans=0;
        int n=colors.size();
        for(int i=0;i<colors.size();){
            if(i+1<colors.size() and colors[i+1]==colors[i]){
                int sum=time[i],mx=time[i];
                int j=i+1;
                while(j<n and colors[j]==colors[i]){
                    sum+=time[j];
                    mx=max(mx,time[j]);
                    j++;
                }
                ans+=sum-mx;
                i=j;
            }
            else i++;
        }
        return ans;
    }
};