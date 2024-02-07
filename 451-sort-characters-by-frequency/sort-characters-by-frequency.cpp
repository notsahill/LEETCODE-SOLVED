class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(char a:s){
            mp[a]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto a:mp){
            pq.push({a.second,a.first});
        }
        string ans="";
        while(pq.size()){
            char ch=pq.top().second;
            int times=pq.top().first;
            for(int i=0;i<times;i++){
                ans+=ch;
            }
            pq.pop();
        }
        return ans;
    }
};