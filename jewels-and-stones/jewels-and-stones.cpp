class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        set<int> s;
        for(char ch1 : jewels){
            s.insert(ch1);
        }
        for(auto a:stones)
        {
            if(s.count(a)) count++;
        }
        return count;
    }
};