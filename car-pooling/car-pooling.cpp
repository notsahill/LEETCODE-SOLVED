class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        unordered_map<int,int> m;
        for(auto a:trips)
        {
            int s=a[1],e=a[2];
            for(int i=s;i<e;i++)
            {
                m[i]+=a[0];
                if(m[i]>capacity) return 0;
            }
        }
        return 1;
    }
};