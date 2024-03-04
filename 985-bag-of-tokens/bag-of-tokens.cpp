class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0,mx=0;
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        while(i<=j){
            if(power>=tokens[i]){
                // cout<<i<<" up"<<endl;
                power-=tokens[i];
                i++;
                score++;
                mx=max(mx,score); 
            }
            else if(power<tokens[i] && score>0){
                // cout<<j<<" down"<<endl;
                power+=tokens[j];
                score--;
                j--;    
            }
            else break;
        }
        return mx;
    }
};