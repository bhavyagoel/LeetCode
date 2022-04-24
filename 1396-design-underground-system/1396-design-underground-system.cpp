class UndergroundSystem {
public:
    map <pair<string, string>, pair<double, int>> stations; 
    unordered_map<int, pair<string, int>> passenger; 
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        passenger[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string station = passenger[id].first; 
        int time = passenger[id].second;
        stations[{station, stationName}].first += (t-time);
        stations[{station, stationName}].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double sum = stations[{startStation, endStation}].first; 
        int cnt = stations[{startStation, endStation}].second; 
        return sum/ cnt; 
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */