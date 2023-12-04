class Solution {
public:
    string largestGoodInteger(string num) {
        for(int i=9;i>=0;i--)
        {
            string temp="";
            temp+=(char)(i+'0');
            temp+=(char)(i+'0');
            temp+=(char)(i+'0');
            if(strstr(num.c_str(),temp.c_str())) return temp;
        }
        return "";
    }
};