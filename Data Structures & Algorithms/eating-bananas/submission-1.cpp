class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;

        for(int i : piles){
            maxPile = max(maxPile, i);
        }

        int l = 1;
        int r = maxPile;
        int minK = INT_MAX;

        

        while(l<=r){
           int mid = (r-l)/2 + l;

            
            int timeTaken = 0 ;

            for(int i = 0; i <piles.size(); ++i){
                timeTaken += (piles[i] + mid - 1) / mid   ;
            }

            if( timeTaken <= h){
                cout<<timeTaken<<endl;
                minK = min(minK,mid);
                r = mid -1;
            }else {
                l = mid + 1;
            }

        }

        return minK;
    }
};
