class TimeMap {
public:
    TimeMap() {
        
    }
    
    unordered_map<string,vector<pair<string,int>>> hashmap;

    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        
        auto it = hashmap.find(key);
        string res="";
        if(it == hashmap.end()){
            return res;
        }
        int n = it->second.size();
        int l = 0;
        int r = n - 1 ;

        while(l<=r){
            int mid = (r-l)/2 + l;

            if(hashmap[key][mid].second <= timestamp){
                res = hashmap[key][mid].first;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

      

        return res;
    }
};
