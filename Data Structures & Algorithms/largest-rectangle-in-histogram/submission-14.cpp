class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        stack<pair<int,int>> st;

        for(int i = 0; i<heights.size();++i){
             pair<int, int> temp = {heights[i],i};
             int area = 0;
            while(!st.empty() && heights[i] < st.top().first){
                temp = st.top();
                st.pop();
                area = temp.first * (i - temp.second);
                maxArea = max(maxArea,area);
            }
            st.push({heights[i],temp.second});
        }

        while(!st.empty()){
            pair<int, int> temp = {st.top().first,st.top().second};
            int area = temp.first * (heights.size() - temp.second);
            maxArea = max(maxArea,area); 
            st.pop();
        }

        return maxArea;
    }
};
