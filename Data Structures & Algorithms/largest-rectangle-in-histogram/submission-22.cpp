class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int maxHeight = 0;
        for(int i=0;i<heights.size();++i){
            int start = i;
            while(!st.empty() && st.top().first > heights[i]){
                maxHeight = max(st.top().first * (i-st.top().second) , maxHeight);
                start = st.top().second;
                st.pop();
            }
            st.push({heights[i],start});
        }

        while(!st.empty()){
            maxHeight = max(st.top().first * ((int)heights.size()-st.top().second) , maxHeight);
            st.pop();
        }

        return maxHeight;
    }
};
