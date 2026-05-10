class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> output(temperatures.size(),0);

        for(int i=0;i<temperatures.size();++i){
            while(!st.empty() && temperatures[i] > st.top().first){
                int diff = i - st.top().second;
                output[st.top().second] = diff;
                st.pop();
            }
            st.push({temperatures[i],i});
        }

        return output;
    }
};
