class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
        if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int c1=0,c2=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                if(i<s.size()/2) c1++;
                else c2++;
            }
        }
        return c1==c2;
    }
};