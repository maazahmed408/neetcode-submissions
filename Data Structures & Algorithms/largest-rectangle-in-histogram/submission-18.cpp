class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int n = heights.size();
        int maxArea = 0;
        for(int i = 0; i<heights.size(); ++i){
            int start = i;
            while(!st.empty() && st.top().first > heights[i]){
                maxArea = max(maxArea , st.top().first * (i - st.top().second));
                start = st.top().second;
                st.pop();
            }
            st.push({heights[i], start});
        }

        while(!st.empty()){
            auto toPop = st.top();
            maxArea = max(maxArea , toPop.first * (n - toPop.second));
                // start = st.top().second;
                st.pop();
        }

        return maxArea;
    }
};
