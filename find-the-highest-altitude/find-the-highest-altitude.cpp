class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int alt=0,pref=0;
        for(int i=0;i<gain.size();i++)
        {
            pref=pref+gain[i];
            alt=max(alt,pref);
        }
        return alt;
    }
};