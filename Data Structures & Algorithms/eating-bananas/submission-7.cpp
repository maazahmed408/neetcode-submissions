class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maximum = INT_MIN;
        for(int i : piles){
            maximum = max(i,maximum);
        }

        int l = 0 , r = maximum;
        int minBanana = INT_MAX;

        while(l<=r){
            int mid = l + (r-l) / 2;
            double time = 0;
            for(int j : piles){
                time += ceil(double(j)/mid);
            }
            if(time > h){
                l = mid+1;
            }else if(time <= h){
                minBanana = min(mid,minBanana);
                r = mid - 1;
            }
        }

        return minBanana;
    }
};
