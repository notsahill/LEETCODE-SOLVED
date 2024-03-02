class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int,vector<int> ,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int ans=0;
        while(pq.size()>=2){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            if(a>=k && b>=k) break;
            long long val=a*2+b;
            ans++;
            int temp=val>=INT_MAX?INT_MAX:val;
            pq.push(temp);
        }
        return ans;
    }
};