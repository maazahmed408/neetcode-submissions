class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int bound = INT_MIN;
        for(int i : piles){
            bound = max(bound,i);
        }

        int l = 1;
        int r = bound;
        int minTime = INT_MAX;

        while(l<=r){
            int mid = (r-l)/2 + l;
            cout<<mid<<endl;
            double time = 0.0;

            for(int i : piles){
                time += ceil((double)i/mid);
            }

            if((int)time <= h){
                 r = mid - 1;
                // minTime = min(mid,minTime);
            }else{
               l = mid +1;

            }

        }

        return l;
    }
};
