class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> loss;
        set<int> participants;
        for(auto match:matches){
            loss[match[1]]++;
            participants.insert(match[0]);
            participants.insert(match[1]);
        }
        vector<int> zeroLoss,oneLoss;
        for(auto a:participants){
            if(loss.find(a)==loss.end()) zeroLoss.push_back(a);
            else{
                if(loss[a]==1) oneLoss.push_back(a);
            }
        }
        return {zeroLoss,oneLoss};
    }
};