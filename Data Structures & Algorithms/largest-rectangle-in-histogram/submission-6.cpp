class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<pair<int,int>> st;
        int maxArea = 0;
        
        for(int i = 0 ; i < heights.size() ; ++i ){
          int start = i;
            while(!st.empty() && st.top().second > heights[i] ){
                pair<int,int> top = st.top();
                int index = top.first;
                int height = top.second;
                int area = (i - index) * height;
                maxArea = max(maxArea,area);
                start = index;
                st.pop();
                
            }

            st.push({start,heights[i]});

            // st.push({i,heights[i]});

        }

        while(!st.empty()){
            int area = (heights.size() - st.top().first) * st.top().second;
            maxArea = max(maxArea,area);
            st.pop();
        }

        return maxArea;
    }
};