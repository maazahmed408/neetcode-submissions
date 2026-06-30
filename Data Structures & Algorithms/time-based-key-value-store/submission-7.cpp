class TimeMap {
    unordered_map<string, vector<pair<int, string>>> timeHash;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeHash[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto emotes = timeHash[key];

        int l = 0;
        int r = emotes.size() -1;
        string res = "";

        while(l<=r){
            int mid = (r-l)/2 + l;
            if(emotes[mid].first < timestamp){
                res = emotes[mid].second;
                l = mid +1 ;
            }else if(emotes[mid].first > timestamp){
                r = mid -1;
            }
            else{
                return emotes[mid].second;
            }
        }

        return res;
    }
};
