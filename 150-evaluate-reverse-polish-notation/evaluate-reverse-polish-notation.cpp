class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;
        for(string s:tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int neeche=st.top(),val;
                st.pop();
                int upar=st.top();
                st.pop();
                if(s=="+") val=upar+neeche;
                if(s=="-") val=upar-neeche;
                if(s=="*") val=upar*neeche;
                if(s=="/") val=upar/neeche;
                st.push(val);
            }
            else{
                int num=stoi(s);
                st.push(num);
            }
        }
        return st.top();
    }
};