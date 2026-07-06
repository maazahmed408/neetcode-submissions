class Solution {
public:
    int climbStairs(int n) {
        int last = 1;
        int secondLast = 1;

        for(int i = n-1 ; i > 0 ; --i){
            int temp = last;
            last = last + secondLast;
            secondLast = temp;

        }

        return last;
    }


};
