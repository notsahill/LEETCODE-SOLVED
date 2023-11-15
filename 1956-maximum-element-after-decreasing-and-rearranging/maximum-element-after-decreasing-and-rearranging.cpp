class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        temp[0]=1;
        for(int i=1;i<temp.size();i++)
        {
            int val=abs(temp[i]-temp[i-1]);
            if(val>1) temp[i]=temp[i-1]+1;
        }
        return temp.back();
    }
};