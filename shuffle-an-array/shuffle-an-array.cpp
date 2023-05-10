class Solution {
public:
    vector<int> n,n1;
    Solution(vector<int>& nums) {
        n=n1=nums;
    }
    
    vector<int> reset() {
        return n1;
    }
    
    vector<int> shuffle() {
        next_permutation(n.begin(),n.end());
        return n;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */