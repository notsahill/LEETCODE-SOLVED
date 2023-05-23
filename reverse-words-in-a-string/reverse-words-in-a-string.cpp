class Solution {
public:
    string reverseWords(string st) 
    {
        stack<string> s;
        string temp="",str="";
        int i=0;
        while(st[i]==' ') i++;
        while(st[st.size()-1]==' ') st.pop_back();
        for(int idx=i;idx<st.size();idx++)
        {
            str+=st[idx];
        }
        cout<<str;
        for(auto a:str)
        {
            if(a==' ' and temp!="") 
            {
                s.push(temp);
                temp="";
            }
            if(a==' ') continue;
            else
            {
                temp+=a;
            }
        }

        s.push(temp);
        string ans="";

        while(s.size())
        {
            if(s.top()==" ") 
            {
                s.pop();
            }
            else
            {
                ans+=s.top()+" ";
                // cout<< s.top()<<endl;
                s.pop();
            }
        }
        ans.pop_back();
        return ans;
    }
};