class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //Extra space using solution
        // unordered_map<int,int> umap;
        // for(int i=0;i<nums.size();i++)
        // {
        //     umap[nums[i]]++;
        // }
        // for(int j=0;j<nums.size();j++)
        // {
        //     int key=nums[j];
        //     auto temp=umap.find(key);
        //     if(temp->second>(nums.size()/2)) return temp->first;
        // }
        // return -1;
        
        //**OPTIMISED SOLUTION (MOORE'S VOTING ALGORITHM)
        int c=0,n=nums.size(),el;
        for(auto a:nums)
        {
            if(c==0) 
            {
                el=a;
                c=1;
            }
            else if(a==el)
            {
                c++;
            }
            else c--;
        }

        int cnt=0;
        for(auto a:nums)
        {
            if(a==el) cnt++;
        }
        if(cnt> n/2) return el;
        return -1;
        // T.C.: 2* O(N)
    }
};