class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> p ;

        for(int i=0;i<position.size();++i){
            p.push_back({position[i],speed[i]});
            }

        sort(p.rbegin(),p.rend());

        stack<double> st;

        for(auto car : p){
            cout<<car.first<<","<<car.second<<endl;
            double time = (double)(target - car.first) / car.second ;
            cout<<time<<endl;
        if(!st.empty() && time <= st.top() ){
            continue;
        } else{
            st.push(time);
        }

        }

    return st.size();


    }
};
