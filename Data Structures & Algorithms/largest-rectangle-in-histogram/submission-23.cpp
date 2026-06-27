class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> bars;
        int maxArea = 0;
        for(int i = 0 ; i<heights.size(); ++i){
            int start = i;
            while(!bars.empty() && bars.top().first > heights[i]){
                auto [height,index] = bars.top();
                bars.pop();
                maxArea = max(maxArea, (i - index) * height );
                start = index;
            }
            bars.push({heights[i],start});
        }

        while(!bars.empty()){
            auto [height,index] = bars.top();
            bars.pop();
            maxArea = max(maxArea, ((int)heights.size() - index) * height );
        }

        return maxArea;
    }
};
