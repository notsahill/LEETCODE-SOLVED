class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        string temp="";
        for(int i=0;i<n;i++)
        {
            temp+=nums[i][i]=='0'?'1':'0';
        }
        return temp;
    }
};