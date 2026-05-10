class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<string,int>>> hashmap;

    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        auto temp = hashmap[key];
        string res = "";
        int l = 0, r = temp.size()-1;

        while(l<=r){
            int mid = (r-l)/2 + l;
            if(temp[mid].second <= timestamp){
                res = temp[mid].first;
                l = mid+1;
            }else{
                r = mid - 1;
            }
        }

        return res;
    }
};
