class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        // unordered_map<int,int> m;
        // vector<int> ans;
        // int n=nums.size();
        // for(auto a:nums)
        // {
        //     m[a]++;
        // }
        // for(auto a:m)
        // {
        //     if(a.second>n/3) ans.push_back(a.first);
        // }
        // return ans;

        //** extended MOORE'S Voting Algorithm
        int c1=0,c2=0,n=nums.size(),el1,el2;
        for(auto a: nums)
        {
            if(c1==0 and a!=el2)
            {
                c1=1;
                el1=a;
            }
            else if(c2==0 and a!=el1)
            {
                c2=1;
                el2=a;
            }
            else if(a==el1) c1++;
            else if(a==el2) c2++;
            else
            {
                c1--,c2--;
            }
        }
        c1=0,c2=0;
        for(auto a:nums)
        {
            if(a==el1) c1++;
            if(a==el2) c2++;
        }
        vector<int> ans;
        if(c1>n/3) ans.push_back(el1);
        if(c2>n/3) ans.push_back(el2);
        return ans;
    }
};