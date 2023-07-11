class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        set<int> s;
        while(j<n)
        {
            if(abs(j-i)>k)
            {
                s.erase(nums[i]);
                i++;
            }

            if(s.count(nums[j])) return 1;

            s.insert(nums[j]);
            j++; 
        }
        return 0;
    }
};