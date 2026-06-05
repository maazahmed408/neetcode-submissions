class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i = 0; i< position.size();++i){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.rbegin(),cars.rend());

        stack<double> time;
        for(int i = 0; i<cars.size();++i){
            double currTime = (double)(target - cars[i].first)/cars[i].second;
            if(!time.empty() && time.top() < currTime){
                time.push(currTime);
            }
            if(time.empty()){
                time.push(currTime);
            }
        }

        return time.size();
    }
};
