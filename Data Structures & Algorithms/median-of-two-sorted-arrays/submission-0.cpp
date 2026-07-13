class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        const vector<int>& A = nums1;
        const vector<int>& B = nums2;

        int m = static_cast<int>(A.size());
        int n = static_cast<int>(B.size());

        int leftSize = (m + n + 1) / 2;

        int low = 0;
        int high = m;

        while (low <= high) {
            int partitionA = low + (high - low) / 2;
            int partitionB = leftSize - partitionA;

            int leftA = (partitionA == 0) ? INT_MIN : A[partitionA - 1];
            int rightA = (partitionA == m) ? INT_MAX : A[partitionA];
            int leftB = (partitionB == 0) ? INT_MIN : B[partitionB - 1];
            int rightB = (partitionB == n) ? INT_MAX : B[partitionB];

            if (leftA <= rightB && leftB <= rightA) {
                if ((m + n) % 2 == 1) {
                    return static_cast<double>(max(leftA, leftB));
                }

                int largestLeft = max(leftA, leftB);
                int smallestRight = min(rightA, rightB);

                return (static_cast<double>(largestLeft) + static_cast<double>(smallestRight)) / 2.0;
            }

            if (leftA > rightB) {
                high = partitionA - 1;
            }

            else {
                low = partitionA + 1;
            }
        }

        return 0.0;
    }
};
