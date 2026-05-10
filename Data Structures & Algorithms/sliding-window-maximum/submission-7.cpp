class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        vector<int> output;
        deque<int> que;
        for(r; r<nums.size();++r){
            if(r-l+1 > k){
                if(!que.empty() && que.front() == l){
                    que.pop_front();
                }
                ++l;
            }
                while(!que.empty() && nums[que.back()] < nums[r]){
                    que.pop_back();
                }
                que.push_back(r);

            if(r>=k-1){
                output.push_back(nums[que.front()])  ;
            }
        }
        return output;
    }
};
