class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;                 // reset one to the start
        
        while (slow != fast) {
            slow = nums[slow];    // both move ONE step now
            fast = nums[fast];
        }
        return slow;

    }
};
