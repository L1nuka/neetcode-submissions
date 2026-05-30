class Solution {
   public:
    int trap(vector<int>& height) {
        int ptrA = 0;
        int ptrB = height.size() - 1;
        int prevA = -1;
        int prevB = -1;
        while (ptrA < height.size() && height[ptrA] >= prevA) {
            prevA = height[ptrA];
            ptrA++;
        }
        ptrA--;
        while (ptrB >= 0 && height[ptrB] >= prevB) {
            prevB = height[ptrB];
            ptrB--;
        }
        ptrB++;

        prevA = height[ptrA];
        prevB = height[ptrB];

        int vol = 0;

        while (ptrA < ptrB) {
            if (prevA < prevB || prevA == prevB) {
                ptrA++;
                if (height[ptrA] < prevA)
                    vol += prevA - height[ptrA];
                else
                    prevA = height[ptrA];
            }
            
            else if (prevB < prevA) {
                ptrB--;
                if (height[ptrB] < prevB)
                    vol += prevB - height[ptrB];
                else
                    prevB = height[ptrB];
            }

            // else
            //     vol+=prevA-height[ptrA++];
        }

        return vol;
    }
};