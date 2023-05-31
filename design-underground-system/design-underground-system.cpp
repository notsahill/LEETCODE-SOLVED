class UndergroundSystem {
private:
    unordered_map <int,pair<string,int>> in; //{id,{from,at time}}
    unordered_map <string,pair<int,int>> out;  // {from->to,{sum of time,count}}
public:
    UndergroundSystem() 
    {
        //default constructor hai
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        in[id].first=stationName;
        in[id].second=t;
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        string s=in[id].first + "-" + stationName;
        out[s].first+=t-in[id].second ;
        out[s].second++;
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        string s=startStation + "-" + endStation;
        int a=out[s].first,b=out[s].second;
        return (double) a/b;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */