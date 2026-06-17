class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        auto coord = [&matrix, &c, &target](int a) {
            int res = matrix[a / c][a % c];
            if (res > target)
                return 1;
            if (res < target)
                return -1;
            return 0;
        };

        int A = 0;
        int B = (r*c)-1;

        while (A <= B) {
            int mid = A + (B-A)/2;
            int result = coord(mid);
            if (result == 1)
                B = mid-1;
            else if (result == -1)
                A = mid+1;
            else
                return true;
        }
        return false;
    }
};
