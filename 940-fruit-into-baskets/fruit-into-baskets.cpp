class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int mx=0;
        int i=0,j=0,n=fruits.size();
        map<int,int> mp;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()==2){
                int val=0;
                for(auto a:mp) val+=a.second;
                mx=max(mx,val);
            }
            while(mp.size()>2 and i<j){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                i++;
            }
            int val=0;
            for(auto a:mp) val+=a.second;
            mx=max(mx,val);
            j++;
        }
        return mx;
    }
};