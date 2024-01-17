class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int,int> umap;
        for(int i=0;i<arr.size();i++)
        {
            umap[arr[i]]++;
        }
       vector<int> v;
        for(auto it:umap)
        {
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==v[i-1]) return 0;
        }
        return 1;
    }
};