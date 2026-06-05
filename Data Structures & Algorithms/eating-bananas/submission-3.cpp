class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxB = 0 ;
        for(int num : piles){
            maxB = max(maxB,num);
        }
        int l = 1 ;
        int r = maxB;
        int minInt = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/ 2;
            int sum = 0;
            for(int nums : piles){
                sum += ceil((double)nums/mid);
            }
            if(sum <= h){
                minInt = min(minInt, mid);
                r = mid -1;
            }else{
                l = mid +1 ;
            }
        }

        return minInt;
    }
};
