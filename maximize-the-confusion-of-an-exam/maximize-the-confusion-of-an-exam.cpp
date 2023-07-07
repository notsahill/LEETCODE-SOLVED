class Solution {
public:
    void update_ans(string s,int k,int &ans,int c,int left,char ch)
    {
        int sz=s.size();
        for(int i=0;i<sz;i++)
        {
            if(s[i]==ch) c++;
            while(c>k)
            {
                if(s[left]==ch) c--;
                left++;
            }
            ans=max(ans,i-left+1);
        }
    }
    int maxConsecutiveAnswers(string s, int k) 
    {
        int c=0,ans=0,left=0; 
        update_ans(s,k,ans,c,left,'F');
        update_ans(s,k,ans,c,left,'T');
        return ans;
    }
};