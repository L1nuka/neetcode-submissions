#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> check;
        for (int i = 0; i < nums.size(); i++){
            int op = target - nums[i];
            auto it = check.find(op);
            if (it != check.end()){
                return {it->second,i};
            }
            check[nums[i]] = i;
        }
    }
};
