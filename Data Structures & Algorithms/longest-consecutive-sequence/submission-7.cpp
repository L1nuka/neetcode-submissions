class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        if (nums.size() == 0)
            return 0;
        set<int> s(nums.begin(), nums.end());
        int max = 0;
        int cur = 1;

        cout << *s.begin() << endl;
        for (auto it = next(s.begin()); it != s.end(); it++){
            if (*(it)-1 != *(prev(it))){
                cout << "miss" << endl;
                if (cur > max)
                    max=cur;
                cur = 1;
            }
            else
                cur++;
            cout << *it << endl;
        }
        if (max > cur)
            return max;
        return cur;
    }
};
