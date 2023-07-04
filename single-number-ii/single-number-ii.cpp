class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]]++;
        }
        for(int j=0;j<nums.size();j++)
        {
            int key=nums[j];
            auto temp=umap.find(key);
            if(temp->second==1) return key;
        }
        return -1;
        
    }
};