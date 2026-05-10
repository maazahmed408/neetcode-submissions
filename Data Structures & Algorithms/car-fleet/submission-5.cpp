class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack <double> st;
        vector<pair<int,int>> cars;
        for(int i = 0 ; i < position.size(); ++i){
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.rbegin(),cars.rend());

        for(auto car : cars){
            double timeTaken = (double)(target - car.first)/car.second;

            if(!st.empty() && timeTaken > st.top()){
                st.push(timeTaken);
            }

            if(st.empty()){
                st.push(timeTaken);
            }

            
        }

        return st.size();
    }
};
