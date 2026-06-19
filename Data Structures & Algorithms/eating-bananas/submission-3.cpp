class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int temp;
        int ptrA = 1;
        int ptrB = -1;
        //+O(n)
        for (auto& x : piles)
            if (x > ptrB)
                ptrB = x;

        int cur = ptrA + (ptrB-ptrA) / 2;
        while (ptrA <= ptrB) {
            temp = sum (piles,cur);
            if (temp > h)
                ptrA = cur + 1;
            if (temp <= h)
                ptrB = cur - 1;
            cur = ptrA + (ptrB-ptrA) / 2;
        }
        return cur;
    }

    int sum(vector<int>& p, int& k) {
        int total = 0;
        for (auto& x : p) total += ceiling(x, k);
        return total;
    }

    int ceiling(int& a, int& b) { return (a + b - 1) / b; }
};
