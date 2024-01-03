class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> temp;
        int ans=0;
        for(int i=0;i<bank.size();i++){
            int c=0;
            for(int j=0;j<bank[0].size();j++){
                if(bank[i][j]=='1') c++;
            }
            if(c>0) temp.push_back(c);
        }
        if(temp.size()<2) return ans;
        for(int i=0;i<temp.size()-1;i++){
            ans+=temp[i]*temp[i+1];
        }
        return ans;
    }
};