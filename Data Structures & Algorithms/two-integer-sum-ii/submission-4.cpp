class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ptrA = 0;
        int ptrB = numbers.size()-1;
        while (numbers[ptrA] + numbers[ptrB] != target){
            int match = numbers[ptrA] + numbers[ptrB];
            if (match > target)
                ptrB--;
            if (match < target)
                ptrA++;
        }
        return {ptrA+1, ptrB+1};
    }
};
