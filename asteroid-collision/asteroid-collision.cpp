class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> ans;
        stack<int> s;
        for(int i=0;i<asteroids.size();i++)
        {
            int ne=asteroids[i];
            if(s.size()==0) 
            {
                s.push(ne);
            }
            else
            {
                int top=s.top();
                if((top>0 and ne>0) or (top<0 and ne<0) or (top<0 and ne>0) ) s.push(ne);
                else 
                {
                    if(abs(top)>abs(ne)){
                    }
                    else if(abs(top)==abs(ne)) s.pop();
                    else 
                    {
                        s.pop();
                        i--;
                    }
                }
            }
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