class Solution {
public:
    int search(vector<int>& nums, int target) {
        int A = 0;
        int B = nums.size()-1;
        int cur;
        while (A <= B) {
            cur = A+(B-A)/2;
            if (nums[cur] > target)
                B = cur-1;
            else if (nums[cur] < target)
                A = cur+1;
            else if (nums[cur] == target)
                return cur;
            else
                return -1;
        }
        return -1;
    }
};
