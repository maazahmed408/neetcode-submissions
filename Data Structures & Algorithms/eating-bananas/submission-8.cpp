class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = INT_MIN;
        int minBanana = INT_MAX;

        for(int i = 0 ; i < piles.size() ; ++i){
            maxPile = max(maxPile, piles[i]);
        }

        int l = 1;
        int r = maxPile;

        while(l<=r){
            int mid = (r-l)/2 + l ;

            double time = 0 ;

            for(int i = 0 ; i < piles.size(); ++i){
                time += ceil(piles[i] / (double)mid ); 
            }

            if(time <= h){
                minBanana = min(minBanana,mid);
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return minBanana;
    }
};
