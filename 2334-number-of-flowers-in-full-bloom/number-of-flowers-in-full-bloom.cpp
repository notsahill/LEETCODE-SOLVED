class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans;
        int n=flowers.size();
        vector<int> started(n),ended(n);
        for(int i=0;i<n;i++)
        {
            started[i]=flowers[i][0];
            ended[i]=flowers[i][1];
        }
        sort(started.begin(),started.end());
        sort(ended.begin(),ended.end());
        for(int i=0;i<people.size();i++)
        {
            int time=people[i];
            int s=upper_bound(started.begin(),started.end(),time)-started.begin();
            int e=lower_bound(ended.begin(),ended.end(),time)-ended.begin();
            cout<<s<<" "<<e<<endl;
            ans.push_back(s-e);
        }
        return ans;
    }
};