class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0;
        for(int k : piles ){
            if(max<k){
                max = k;
            }
        }

        int l = 1;
        int r = max;
        int k ;
        int result=INT_MAX;
        while(l <= r){
            k = (l + r)/2;
            double time = 0;
            for(int i=0; i < piles.size() ; i++){
                time += ceil((double)piles[i] / k);
            }
            cout<<"t:"<<time<<"-k:"<<k<<endl;
        if(time <= h){
            result = min(k,result);
            r = k-1;
        }else{
            l = k + 1;
        }
        }
        cout<<result;
        return result;
    }
};
