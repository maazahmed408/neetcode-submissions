class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> output(temperatures.size(), 0);
        stack<pair<int, int>> st;
        // {30 , 0} 

        for(int i=0 ; i < temperatures.size(); ++i){
            while(!st.empty() && st.top().first < temperatures[i]){
                auto temp = st.top();
                st.pop();
                output[temp.second] = i - temp.second ;
            }
            st.push({temperatures[i] , i});
        }

        return output;
    }
};
