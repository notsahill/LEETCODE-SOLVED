class Solution {
public:
    typedef pair<float,pair<int,int>> pi;
    // #define pair<double,pair<int,int>> pdpii
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
    {
        priority_queue<pi,vector<pi>,greater<pi> > q;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                float f=(arr[i]*1.0)/arr[j];
                // cout<<f<<" "<<arr[i]<<","<<arr[j]<<endl;
                q.push({f,{arr[i],arr[j]}});
            }
        }
        // cout<<endl<<endl;
        vector<int> ans;
        // while(q.size())
        // {
        //     int i=q.top().second.first;
        //     int j=q.top().second.second;
        //     cout<<q.top().first<<" "<<i<<","<<j<<endl;
        //     q.pop();
        // }
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