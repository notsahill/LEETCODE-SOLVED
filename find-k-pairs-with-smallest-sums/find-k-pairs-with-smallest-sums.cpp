class Solution {
public:
    #define pp pair<int,pair<int,int>> 
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        priority_queue<pp> pq;
        vector<vector<int>> ans;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(pq.size()<k) pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                else if(pq.top().first>nums1[i]+nums2[j])
                {
                    pq.pop();
                    pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                }
                else break; // kyunki since nums2 sorted hai toh aage saari sum ki values currently present values se badi hi aaengi
            }
        }
        while(k-- and pq.size())
        {
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;
    }
};
//BRUTE-FORCE TLE solution
// #define pp pair<int,pair<int,int>> 
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
//     {
//         priority_queue<pp, vector<pp>, greater<pp> > pq;
//         for(int i=0;i<nums1.size();i++)
//         {
//             for(int j=0;j<nums2.size();j++)
//             {
//                 pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
//             }
//         }
//         vector<vector<int>> ans;
//         while(k-- and pq.size())
//         {
//             int x=pq.top().second.first;
//             int y=pq.top().second.second;
//             ans.push_back({x,y});
//             pq.pop();
//         }
//         return ans;
//     }