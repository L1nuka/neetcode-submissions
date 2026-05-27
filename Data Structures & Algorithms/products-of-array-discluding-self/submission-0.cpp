class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int Zeros = 0;
        int product = 1;
        for (const auto& x : nums){
            if (x == 0)
                Zeros++;
            else
                product*=x;
        }
        if (Zeros > 1){
            vector<int> v(nums.size());
            return v;
        }
        vector<int> ans = nums;
        for (auto& x : ans){
            if (x==0){
                x=product;
            }
            else if (Zeros == 1)
                x=0;
            else
                x=product/x;
        }
        return ans;
    }
};
