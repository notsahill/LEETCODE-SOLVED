class Solution {
public:
    int minOperations(string s) {
        string a="",b="";
        int n=s.size();
        for(int i=0;i<n;i++){
            a+="1";
            b+="0";
        }
        for(int i=1;i<n;i+=2){
            a[i]='0';
            b[i]='1';
        }
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(a[i]!=s[i]){
                c1++;
            }
            if(b[i]!=s[i]){
                c2++;
            }
        }
        return min(c1,c2);
    }
};