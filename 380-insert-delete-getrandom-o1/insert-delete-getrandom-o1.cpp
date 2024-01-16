class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        else{
            mp[val]=(int)v.size();
            v.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end())
        {
            int idx=mp[val],last=v.back();
            v[idx]=last;
            mp[last]=idx;
            v.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int idx=rand()%v.size();
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */