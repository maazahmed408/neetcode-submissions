class TimeMap {
    unordered_map<string,vector<pair<int,string>>> tm;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string output = "";
        if(tm.count(key)){
            auto& arr = tm[key];
            
            int l = 0 ;
            int r = arr.size()-1;

            while(l <= r){
                int mid = (r-l)/2 + l ;

                if(arr[mid].first < timestamp){
                    output = arr[mid].second;
                    l = mid + 1;
                }else if(arr[mid].first > timestamp){
                    r = mid -1;
                }else{
                    return arr[mid].second;
                }
            }
        }

        return output;
    }
};
