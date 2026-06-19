class Solution {
public:
    int findMin(vector<int> &nums) {
        int ptrA = 0;
        int ptrB = nums.size()-1;
        if (nums[ptrB] > nums[ptrA])
            return nums[ptrA];
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return min(nums[0],nums[1]);
        int cur = ptrA + (ptrB-ptrA)/2;
        while (ptrA <= ptrB) {
            if (nums[cur] > nums[ptrA]){
                ptrA = cur + 1;
            }

            else if (nums[cur] < nums[ptrA]){
                ptrB = cur - 1;
            }

            if (nums[cur] > nums[cur+1])
                return nums[cur+1];
            if (nums[cur] < nums[cur-1])
                return nums[cur];

            cur = ptrA + (ptrB-ptrA)/2;
        }
        return -1;
    }
};
