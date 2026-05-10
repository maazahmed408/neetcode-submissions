class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    
    vector<pair<int,int>> cars(position.size());
    for(int i = 0; i < position.size(); ++i){
        cars[i].first = position[i]; 
        cars[i].second = speed[i]; 
    }
    sort(cars.begin(),cars.end());

    stack<double> time;
    for(auto car : cars){
        double timeTaken = (double)(target - car.first) / (double)car.second;
        while(!time.empty() && time.top() <= timeTaken ){
            time.pop();
            // time.push(timeTaken);
        }
        time.push(timeTaken);
    }

    return time.size();

    }
};
