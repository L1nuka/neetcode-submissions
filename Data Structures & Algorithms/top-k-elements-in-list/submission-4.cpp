#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (auto& x : nums)
            freq[x]++;

        for (auto& x : freq)
            cout << x.first <<','<< x.second << endl;

        vector<int> result;
        for (int i = 0; i < k; i++){
            auto it = freq.begin();
            for (auto& x : freq){
                if (x.second > it->second)
                    it = freq.find(x.first);
            }
            result.push_back(it->first);
            freq.erase(it->first);
        }
        return result;
    }
};
