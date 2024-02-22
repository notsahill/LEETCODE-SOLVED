class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n+1,0);
        for(auto trusti:trust){
            trustCount[trusti[1]]++,trustCount[trusti[0]]--;
        }
        for(int i=1;i<=n;i++){
            if(trustCount[i]==n-1) return i;
        }
        return -1;
    }
};