class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> st;
        for(char ch:word){
            st.insert(ch);
        }
        int c=0;
        for(char ch:st){
            if(ch>=65 && ch<=90){
                if(st.count(ch+32)) c++;
            }
            else{
                if(st.count(ch-32)) c++;
            }
        }
        return c/2;
    }
};