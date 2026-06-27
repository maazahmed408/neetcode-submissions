class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        stack<double> st;
        for(int i =0 ; i < position.size(); ++i){
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(),cars.end());

        for(int i=cars.size()-1; i >= 0; --i){
            double time = double(target - cars[i].first) / cars[i].second ;
            if(!st.empty() && st.top() < time || st.empty()) st.push(time);
            else continue;
        }

        return (int)st.size();


    }
};
// [0,1,4,7] -> [3,4.5,10]