class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ptrA = 0;
        int ptrB = nums.size() - 1;
        int cur;
        while (ptrA <= ptrB){
            cur = ((ptrB - ptrA) / 2) + ptrA;
            if (nums[cur] == target)
                return cur;
            if (nums[cur] >= nums[ptrA]) {
                if (nums[cur] > target && nums[ptrA] <= target)
                    ptrB = cur - 1;
                else
                    ptrA = cur + 1;
            }

            else {
                if (nums[cur] < target && nums[ptrB] >= target)
                    ptrA = cur + 1;
                else
                    ptrB = cur - 1;
            }
        }
        return -1;
    }
};
