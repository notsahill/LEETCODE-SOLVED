class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> cities,start;
        for(auto a:paths){
            start.insert(a[0]);
            cities.insert(a[0]);
            cities.insert(a[1]);
        }
        for(auto a:cities){
            if(!start.count(a)) return a;
        }
        return "";
    }
};