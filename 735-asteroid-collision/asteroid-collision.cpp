class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> ans;
        stack<int> s;
        for(auto a:asteroids)
        {
            while(s.size() and s.top()>0 and a<0)
            {
                int sum=(int)s.top()+a;
                if(sum<0)
                {
                    s.pop();
                }
                else if(sum>0)
                {
                    a=0;
                }
                else
                {
                    s.pop();
                    a=0;
                }
            }
            if(a!=0) s.push(a);
        }
        while(s.size())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};