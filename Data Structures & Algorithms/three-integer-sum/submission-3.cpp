class Solution {
public:

    vector<vector<int>> twoSum(vector<int>& numbers, int target, int ind) {
        int ptrA = ind;
        int ptrB = numbers.size()-1;
        vector<vector<int>> matches;
        while (ptrA < ptrB){
            int match = numbers[ptrA] + numbers[ptrB];
            if (match > target)
                ptrB--;
            if (match < target)
                ptrA++;
            if (match == target){
                matches.push_back({-target, numbers[ptrA], numbers[ptrB]});
                int stateA = numbers[ptrA];
                int stateB = numbers[ptrB];
                while (ptrA != numbers.size() && numbers[ptrA]==stateA)
                    ptrA++;
                while (ptrB != -1 && numbers[ptrB]==stateB)
                    ptrB--;
                }
            
        }
        return matches;

        //numbers[ptrA] + numbers[ptrB] != target
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> trios;
        for (int i = 0; i < nums.size(); i++){
            if (i!=0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            auto v2 = twoSum(nums, target, i+1);
            trios.insert(trios.end(), v2.begin(), v2.end());
        }
        return trios;
    }
};

