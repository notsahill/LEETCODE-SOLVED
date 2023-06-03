class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int n=cardPoints.size();
        int mx=0,sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=cardPoints[i];
        }
        mx=sum;
        for(int l=k-1,h=n-1;l>=0;l--,h--)
        {
            sum+=cardPoints[h]-cardPoints[l];
            mx=max(mx,sum);
        }
        return mx;
    }
};