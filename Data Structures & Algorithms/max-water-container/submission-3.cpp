class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ptrA = 0;
        int ptrB = heights.size()-1;
        auto volume = [&heights](int a, int b){return min(heights[a], heights[b])*(b-a);};
        int max = volume(ptrA,ptrB);
        int cur = 0;
        while (ptrA < ptrB){
            cur = volume(ptrA,ptrB);
            max = (cur > max) ? cur : max;
            (heights[ptrA] < heights[ptrB]) ? ptrA++ : ptrB--;
        }
        return max;
    }
};
