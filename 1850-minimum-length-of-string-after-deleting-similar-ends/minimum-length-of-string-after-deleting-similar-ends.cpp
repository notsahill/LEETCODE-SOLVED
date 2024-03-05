class Solution {
public:
    int minimumLength(string s) {
        int n=s.size(),i=0,j=n-1;
        while(i<j && s[i]==s[j]){
            char f=s[i],b=s[j];
            while(i<j && s[i]==f) i++;
            while(i<=j && s[j]==b) j--;
        }
        return j-i+1;
    }
};