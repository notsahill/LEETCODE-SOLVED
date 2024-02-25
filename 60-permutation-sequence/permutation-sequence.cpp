class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++){
            string temp=to_string(i);
            s+=temp;
        }    
        while(k>1){
            next_permutation(s.begin(),s.end());
            k--;
        }
        return s;
    }
};