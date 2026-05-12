#include <unordered_set>
using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set<int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            m.insert(nums[i]);
        if (m.size() < n)
            return true;
        return false;
    }
};