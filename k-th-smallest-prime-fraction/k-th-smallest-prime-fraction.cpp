class Solution {
public:
    typedef pair<float,pair<int,int>> pi;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
    {
        priority_queue<pi,vector<pi>,greater<pi> > q;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                float f=(arr[i]*1.0)/arr[j];
                q.push({f,{arr[i],arr[j]}});
            }
        }
        vector<int> ans;
        while(k--)
        {
            int i=q.top().second.first;
            int j=q.top().second.second;
            ans={i,j};
            q.pop();
        }
        return ans;
    }
};