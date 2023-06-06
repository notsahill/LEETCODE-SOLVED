class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        vector<bool> ans(l.size(),1);
        for(int i=0;i<l.size();i++)
        {
            int from=l[i],to=r[i];
            if(to-from+1<=1) 
            {
                ans[i]=0;
                continue;
            }
            vector<int> temp;
            for(int i=from;i<=to;i++)
            {
                temp.push_back(nums[i]);
            }
            sort(temp.begin(),temp.end());
            int d=temp[1]-temp[0];
            for(int j=1;j<temp.size();j++)
            {
                if(temp[j]-temp[j-1]!=d) ans[i]=0;
            }
        }
        return ans;
    }
};