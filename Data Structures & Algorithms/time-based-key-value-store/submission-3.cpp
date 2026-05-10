class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<string,int>>> hashmap;

    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        string output ="";
        auto it = hashmap.find(key);

        if(it == hashmap.end()){return output;}

        auto& arr = it->second;

        int l = 0 , r = arr.size()-1;

        while(l<=r){
            int mid = (r-l)/2 + l;

            if(arr[mid].second <= timestamp){
                output = arr[mid].first;
                l = mid + 1;
            }
            else{
                r = mid -1;
            }
        }

        return output;
    }
};
