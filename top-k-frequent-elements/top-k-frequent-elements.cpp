class Solution {
public: 
    typedef pair<int,int> pii;
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map <int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pii> pq;
        for(auto a:m)
        {
            pair<int,int> p={a.second,a.first};
            pq.push(p);
        } 
        vector <int> ans;
        for(int i=0;i<k;i++)
        {
            pair<int,int> p=pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};