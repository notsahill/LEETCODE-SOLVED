class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string res="";
        int n=s.size();
        for(int i=0;i<numRows;i++){
            int jump=2*(numRows-1);
            for(int j=i;j<n;j+=jump){
                res+=s[j];
                if(i>0 and i<numRows-1 and j+jump-2*i<n){
                    res+=s[j+jump-2*i];
                }
            }
        }
        return res;
    }
};